
%% process input variables
function varargout = drawCenteredEdge(varargin)
if nargin < 1
    error('Function requires an input argument');
end

% extract handle of axis to draw on
%if isAxisHandle(varargin{1})
    ax = varargin{1};
    varargin(1) = [];
%else
%    ax = gca;
%end

var = varargin{1};
if size(var, 2) == 4
    % manage edge in single parameter
    len     = var(:, 3);
    theta   = var(:, 4);
    center  = var(:, 1:2);

    N = size(center, 1);    
    varargin(1) = [];

elseif length(varargin) >= 3
    % parameters given in different arguments
    
    % size of data
    center  = varargin{1};
    len     = varargin{2};
    theta   = varargin{3};
    varargin(1:3) = [];

    % ensure all data have same size
    NP = size(center, 1);
    NL = size(len, 1);
    ND = size(theta, 1);
    N  = max([NP NL ND]);
    if N > 1
        if NP == 1, center = repmat(center, [N 1]); end
        if NL == 1, len = repmat(len, [N 1]); end
        if ND == 1, theta = repmat(theta, [N 1]); end
    end
    
end

% extract drawing options
options = varargin(:);


%% Draw edges

% coordinates of center point
xc = center(:, 1);
yc = center(:, 2);

% convert angle to radians
theta = theta * pi / 180;

% computation shortcuts
cot = cos(theta);
sit = sin(theta);

% compute starting and ending points
x1 = xc - len .* cot / 2;
x2 = xc + len .* cot / 2;
y1 = yc - len .* sit / 2;
y2 = yc + len .* sit / 2;


% draw the edges
h = zeros(N, 1);
for i = 1:N
    h(i) = plot(ax, [x1(i) x2(i)], [y1(i) y2(i)]);
end

% apply style to edges
if ~isempty(options) > 0
    for i = 1:N
        set(h(i), options{:});
    end
end


%% Format output

% process output arguments
if nargout > 0
    varargout = {h};
end