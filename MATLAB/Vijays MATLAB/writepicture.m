function writepicture(picture)
%%%%% Writes jpeg from non-delimited numerical string %%%%%
jpegmat=zeros(100000);

for i=1:floor(length(picture)/3)
%%%%% Each byte is given as 3 values each             %%%%%
    bytestart=1+3*(i-1);
    value=pictures(bytestart)*100+pictures(bytestart+1)*10+...
        pictures(bytestart+2)*1;
    jpegmat(i)=value;
end
jpegmat=jpegmat(1:i);

%%%%% Turn jpegmat into a jpeg                        %%%%%


%%%%% Write jpeg to file                              %%%%%
imwrite(pic,'transmittedpicture.jpeg','fmt',jpeg,'BitDepth',8);

end