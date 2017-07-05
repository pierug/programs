I = imread('tygrys.jpeg');
J = rgb2gray(I);
B = (J > 100)&(J < 240);
subplot(1,2,1);
B = bwmorph(B,'majority');
imshow(B);
[B, map] = gray2ind(B, 65536);
RGB = ind2rgb(B,map);
[r c z] = size(RGB);
for i=1:r
    for j=1:c   
        if((RGB(i,j,1)==1))
            RGB(i,j,1) = 0;
            RGB(i,j,2) = 0;
            RGB(i,j,3) = 255;
        else
            RGB(i,j,1) = 255;
            RGB(i,j,2) = 0;
            RGB(i,j,3) = 255;
        end
    end
end
subplot(1,2,2);
imshow(RGB);