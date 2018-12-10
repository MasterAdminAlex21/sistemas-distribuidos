#include <bits/stdc++.h>

using namespace std;

void ReadBMP(char* filename, int x, int y)
{
	int pos = 0;
	int posBit = 0;
	int i;
	FILE* f = fopen(filename, "rb");

	if(f == NULL)
		throw "Argument Exception";

	unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;
    unsigned char **red, **green, **blue;
	
	red = new unsigned char*[width + 5];
	green = new unsigned char*[width + 5];
	blue = new unsigned char*[width + 5];
	for(int j = 0; j < width; j++){
		red[j] = new unsigned char[height + 5];
		blue[j] = new unsigned char[height + 5];
		green[j] = new unsigned char[height + 5];
	}
    for(int i = 0; i < height; i++)
    {
    	fread(data, sizeof(unsigned char), row_padded, f);
    	for(int j = 0; j < width*3; j += 3)
    	{
            // Convert (B, G, R) to (R, G, B)
    		tmp = data[j];
    		data[j] = data[j+2];
    		data[j+2] = tmp;
    		red[j / 3][i] = data[j];
    		green[j / 3][i] = data[j];
    		blue[j / 3][i] = data[j];
			

    		//cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< endl;
    	}
    }
	printf("aste4[%d][%d] = ", width, height);
	printf("{");
	for(int i = 0; i < width; i++){
		printf("{");
		for(int j = 0; j < height; j++){
			if(j)
				printf(", ");
			printf("%d", red[i][j] ? 1 : 0);
			
		}
		printf("}");
		if(i != width - 1)
			printf(",\n");
	}
	printf("}");
    fclose(f);
    FILE *f2;
    unsigned char *img = NULL;
	int filesize = 54 + 3*width*height;  //w is your image width, h is image height, both int
	if( img )
		free( img );
	img = (unsigned char *)malloc(3*width*height);
	memset(img,0,sizeof(img));

	for(int i=0; i<width; i++)
	{
		for(int j=0; j<height; j++)
		{
			int x=i; 
			int y=(height-1)-j;
			img[(x+y*width)*3+2] = (unsigned char)(red[i][j]);
			img[(x+y*width)*3+1] = (unsigned char)(green[i][j]);
			img[(x+y*width)*3+0] = (unsigned char)(blue[i][j]);
		}
	}

	unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
	unsigned char bmppad[3] = {0,0,0};

	bmpfileheader[ 2] = (unsigned char)(filesize    );
	bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
	bmpfileheader[ 4] = (unsigned char)(filesize>>16);
	bmpfileheader[ 5] = (unsigned char)(filesize>>24);

	bmpinfoheader[ 4] = (unsigned char)(       width    );
	bmpinfoheader[ 5] = (unsigned char)(       width>> 8);
	bmpinfoheader[ 6] = (unsigned char)(       width>>16);
	bmpinfoheader[ 7] = (unsigned char)(       width>>24);
	bmpinfoheader[ 8] = (unsigned char)(       height    );
	bmpinfoheader[ 9] = (unsigned char)(       height>> 8);
	bmpinfoheader[10] = (unsigned char)(       height>>16);
	bmpinfoheader[11] = (unsigned char)(       height>>24);
/*
	f2 = fopen("asteroide1.bmp","wb");
	fwrite(bmpfileheader,1,14,f2);
	fwrite(bmpinfoheader,1,40,f2);
	for(i=0; i<height; i++)
	{
		fwrite(img+(width*(height-i-1)*3),3,width,f2);
		fwrite(bmppad,1,(4-(width*3)%4)%4,f2);
	}
	fclose(f2);*/
	//puts("The name of image is img2.bmp");
}

int main(){
	char direccion[] = "asteroide5.bmp";
	int x;
	ReadBMP(direccion, x, 0);
	return 0;
}