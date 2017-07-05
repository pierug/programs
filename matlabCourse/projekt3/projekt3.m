input = imread('LungCancer.jpg');

grayImage=rgb2gray(input);

figure,imshow(grayImage),title('Obraz w skali szarosci');

binGrayImage = (grayImage > 100)&(grayImage < 240);
figure, imshow(binGrayImage), title('obraz binarny')

se = strel('line',7,7);
erodeGrayImage = imerode(grayImage,se);

figure, imshow(erodeGrayImage), title('obraz po erozji')  

dilGrayImage = imdilate(grayImage,se);
figure, imshow(dilGrayImage), title('obraz po dylatacji')


skeletonBinGrayImage = bwmorph(binGrayImage,'skel',7);
figure, imshow(skeletonBinGrayImage),title('obraz po szkieletyzacji')

dilatenBinGrayImage = bwmorph(binGrayImage, 'dilate');
figure, imshow(dilatenBinGrayImage),title('Binarny obraz po dylatacji')

erodeBinGrayImage = bwmorph(binGrayImage, 'erode'); 
figure, imshow(erodeBinGrayImage),title('Binarny obraz po erozji')

skeletonBinGrayImage = bwmorph(binGrayImage, 'skel');
figure, imshow(skeletonBinGrayImage),title('Binarny obraz po szkieletyzacji')

openBinGrayImage = bwmorph(binGrayImage, 'open');
figure, imshow(openBinGrayImage),title('Binarny obraz po otwarciu')

closeBinGrayImage = bwmorph(binGrayImage, 'close'); 
figure, imshow(closeBinGrayImage),title('Binarny obraz po zamkniêciu')


medianeGrayImage=medfilt2(grayImage,[5 5]);
medAndAdjust = imadjust(medianeGrayImage,stretchlim(grayImage),[]);
figure, imshow(medAndAdjust),title('Obraz po filtrze medianowym[5 5] i dostosowaniu wartoœci intensywnoœci obrazu');

