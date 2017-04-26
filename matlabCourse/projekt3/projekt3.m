input = imread('LungCancer.jpg');

grayImage=rgb2gray(input);

figure,imshow(grayImage),title('Obraz w skali szarosci');

binGrayImage = (grayImage > 100)&(grayImage < 240);
%figure, imshow(binGrayImage), title('obraz binarny')


se = strel('line',7,7);
erodeGrayImage = imerode(grayImage,se);

%figure, imshow(erodeGrayImage), title('obraz po erozji')  

dilGrayImage = imdilate(grayImage,se);
%figure, imshow(dilGrayImage), title('obraz po dylatacji')


%skeletonBinGrayImage = bwmorph(binGrayImage,'skel',7);
%figure, imshow(skeletonBinGrayImage),title('obraz po szkieletyzacji')

dilatenBinGrayImage = bwmorph(binGrayImage, 'dilate');
%figure, imshow(dilatenBinGrayImage),title('Binarny obraz po dylatacji')

erodeBinGrayImage = bwmorph(binGrayImage, 'erode'); 
%figure, imshow(erodeBinGrayImage),title('Binarny obraz po erozji')

skeletonBinGrayImage = bwmorph(binGrayImage, 'skel');
%figure, imshow(skeletonBinGrayImage),title('Binarny obraz po szkieletyzacji')

openBinGrayImage = bwmorph(binGrayImage, 'open');
%figure, imshow(openBinGrayImage),title('Binarny obraz po otwarciu')

closeBinGrayImage = bwmorph(binGrayImage, 'close'); 
%figure, imshow(closeBinGrayImage),title('Binarny obraz po zamkniêciu')


medianeGrayImage=medfilt2(grayImage,[5 5]);
medAndAdjust = imadjust(medianeGrayImage,stretchlim(grayImage),[]);
%figure, imshow(medAndAdjust),title('Obraz po filtrze medianowym[5 5] i dostosowaniu wartoœci intensywnoœci obrazu');


%L = watershed(grayImage);
%figure, imshow(L),title('');

%[cs, h] = imcontour(grayImage, 6);
%clabel(cs, h);

I=grayImage;

hy = fspecial('sobel');
hx = hy';
Iy = imfilter(double(I), hy, 'replicate');
Ix = imfilter(double(I), hx, 'replicate');
gradmag = sqrt(Ix.^2 + Iy.^2);
figure
imshow(gradmag,[]), title('Gradient magnitude (gradmag)')

L = watershed(gradmag);
Lrgb = label2rgb(L);
figure, imshow(Lrgb), title('Watershed transform of gradient magnitude (Lrgb)')
se = strel('disk', 5);
Io = imopen(I, se);
figure
imshow(Io), title('Opening (Io)')


Ie = imerode(I, se);
Iobr = imreconstruct(Ie, I);
figure
imshow(Iobr), title('Opening-by-reconstruction (Iobr)')


Ioc = imclose(Io, se);
figure
imshow(Ioc), title('Opening-closing (Ioc)')

Iobrd = imdilate(Iobr, se);
Iobrcbr = imreconstruct(imcomplement(Iobrd), imcomplement(Iobr));
Iobrcbr = imcomplement(Iobrcbr);
figure
imshow(Iobrcbr), title('Opening-closing by reconstruction (Iobrcbr)')

fgm = imregionalmax(Iobrcbr);
figure
imshow(fgm), title('Regional maxima of opening-closing by reconstruction (fgm)')


I2 = I;
I2(fgm) = 255;
figure
imshow(I2), title('Regional maxima superimposed on original image (I2)')

se2 = strel(ones(1,1));
fgm2 = imclose(fgm, se2);
fgm3 = imerode(fgm2, se2);


fgm4 = bwareaopen(fgm3, 5);
I3 = I;
I3(fgm4) = 255;
figure
imshow(I3)
title('Modified regional maxima superimposed on original image (fgm4)')

bw = imbinarize(Iobrcbr);
figure
imshow(bw), title('Thresholded opening-closing by reconstruction (bw)')

D = bwdist(bw);
DL = watershed(D);
bgm = DL == 0;
figure
imshow(bgm), title('Watershed ridge lines (bgm)')



gradmag2 = imimposemin(gradmag, bgm | fgm4);


L = watershed(gradmag2);


I4 = I;
I4(imdilate(L == 0, ones(1, 1)) | bgm | fgm4) = 255;
figure
imshow(I4)
title('Markers and object boundaries superimposed on original image (I4)')


Lrgb = label2rgb(L, 'jet', 'w', 'shuffle');
figure
imshow(Lrgb)
title('Colored watershed label matrix (Lrgb)')

figure
imshow(I)
hold on
himage = imshow(Lrgb);
himage.AlphaData = 0.3;
title('Lrgb superimposed transparently on original image')




























