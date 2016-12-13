S = zeros(150,150);
for i=1:150
    for j=1:150
        if(mod(i,2))
           if(mod(j,2)~=0)
               S(i,j) = 1;
           else
               S(i,j) = 0;
           end
        else
            if(mod(j,2)~=0)
               S(i,j) = 0;
           else
               S(i,j) = 1;
           end
        end
    end
end
imshow(S)
