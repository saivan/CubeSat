function WODdecode(WOD)
%%%%% Converts to string, and reads timestamp %%%%%
infostring=char(WOD);
Time=infostring(1:4);
n=length(infostring);
nsets=floor(n/8);

Mode=zeros(nsets,1);
BattV=zeros(nsets,1);
BattI=zeros(nsets,1);
FVI=zeros(nsets,1);
TVI=zeros(nsets,1);
CommT=zeros(nsets,1);
EPST=zeros(nsets,1);
BattT=zeros(nsets,1);
    
    %%%%% Loop reads ordered sensor values        %%%%%
    %%%%% Each WOD set consists of 8 bytes        %%%%%
    
    for i=1:nsets;
        
        Mode(i)=infostring(5+8*i);
        BattV(i)=infostring(6+8*i)/20+3;
        BattI(i)=infostring(7+8*i)/127-1;
        FVI(i)=infostring(8+8*i)/40;
        TVI(i)=infostring(9+8*i)/40;
        CommT(i)=infostring(10+8*i)/4-15;
        EPST(i)=infostring(11+8*i)/4-15;
        BattT(i)=infostring(12+8*i)/4-15;
        
    end
    
    WOD=[Mode BattV BattI FVI TVI CommT EPST BattT];
end
