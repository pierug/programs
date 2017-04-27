img = imread('LungCancer.jpg');

img=rgb2gray(img);


% compute background
bg = imopen(img, ones(50, 50));
img2 = img - bg;
figure(2); clf;
imshow(img2);

% display histogram, to identify the threshold value
figure(3); clf;
imhist(img2);

% image binarisation, and remove particles touching border
bin = img2 > 140;
bin = imclearborder(bin, 18);
figure ,imshow(bin);

% compute image labels, using minimal connectivity
lbl = bwlabel(bin, 4);
nLabels = max(lbl(:));

stats = regionprops('table',bin,'Centroid','MajorAxisLength','MinorAxisLength');
centers = stats.Centroid
diameters = mean([stats.MajorAxisLength stats.MinorAxisLength],2);
radii = diameters/2;
fixedSize=0;
for i=1:size(centers)
    if diameters(i)>50
        fixedSize=fixedSize+1;
    end
end

fixedDiameters=zeros(fixedSize,1);
fixedCenters=zeros(fixedSize,2);
j=1;
for i=1:size(centers)
    if diameters(i)>50
        fixedCenters(j,1) = centers(i,1);
        fixedCenters(j,2) = centers(i,2);
        fixedDiameters(j) = diameters(i);
        j=j+1;
    end
end

fixedradii = fixedDiameters/2;
% display label image
rgb = label2rgb(lbl, jet(nLabels), 'w', 'shuffle');
figure(4); clf;

RGB = insertText(rgb,fixedCenters,fixedDiameters,'FontSize',25,'AnchorPoint','LeftBottom');
imshow(RGB);

hold on
viscircles(fixedCenters,fixedradii);
hold off

