
file='/Users/daniel/.fldigi/fldigi20141021.log';
%file='fldigi20141009.log';
fid = fopen(file);

tline = fgets(fid);
lineCount=0;
totalframes=0;

picturesglobal=[];
classesglobal=[];
WODglobal=[];

while 1
    
    
    if(strfind(tline, sprintf('\n')))
        lineCount=lineCount+1;
        
        [pictureslocal,WODlocal,classeslocal,tlframes]=AX25decode3(tline);
        totalframes=totalframes+tlframes;
        classes=[classesglobal;classes];
        WOD=[WODglobal;WOD];
        pictures=[picturesglobal pictures];
        
        %disp(tline)
         tline = fgets(fid);
         
    else
        pause(1);
        fid = fopen(file);
             for i=1:lineCount
                 tline = fgets(fid);
             end

        tline = fgets(fid);
    
    end
        

end
