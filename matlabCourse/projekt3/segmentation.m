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
bin = img2 > 60;
bin = imclearborder(bin, 18);
imshow(bin);

% compute image labels, using minimal connectivity
lbl = bwlabel(bin, 4);
nLabels = max(lbl(:));

% display label image
rgb = label2rgb(lbl, jet(nLabels), 'w', 'shuffle');
figure(4); clf;
imshow(rgb);



% compute diameters with corresponding angles
[diams thetas] = imMaxFeretDiameter(lbl);

% also compute centroids
centros = imCentroid(lbl);

% overlay result on image
hold on;
drawCenteredEdge([centros diams thetas], 'linewidth', 2, 'color', 'k');