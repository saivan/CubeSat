tline='RTTY~DESTINpADDRESpCPinformationblahFC~~DESTINpADDRESpCPdifferentinfoblahFC~';
tline=tline*1;

for i=1:length(tline)
    if(tline(i)~='~')
        if(floor(tline(i)/2)<94)
        tline(i)=floor(tline(i)/2)+32;
        else
        tline(i)=floor(tline(i)/2)+66;
        end
    end
end

tline=char(tline);