///////////////////////
// 2016250033 ���켷 //
///////////////////////

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int array[n][n];
	
	int cnt=1,i,j,layer=0, LastLayer = (n-1)/2;
	
	while(1)
	{
		if(layer == LastLayer) // ������ layer�� ���������� 
		{
			if(n%2 == 1)	//Ȧ���� 
			{
				array[n/2][n/2]=n*n; // ���߾� ���Ҹ� n*n�� ä��� ���� 
				break;
			}
			else			//¦���� 
			{
				for(i=LastLayer; i<= LastLayer+1; i++)	// -> ä��� 
					array[LastLayer][i] = cnt++;	
				for(i=LastLayer+1; i>= LastLayer; i--)	// <- ä��� 
					array[LastLayer+1][i] = cnt++;	
				break;
			}	
		}
		else
		{
			for(i=0; i < n-(layer*2)    ; i++)					//�� Layer�� ����(������)(���)
				array[layer][i+layer] = cnt++;
			
			
			for(i=0; i < n-(layer*2) -1 ; i++)					//�� layer�� �ι�° (������)(����)
				array[i+layer+1][(n-1)-layer] = cnt++;
			
			
			for(i=0; i < n-(layer*2) -1 ; i++)					//�� layer�� ����° (������)(�ϴ�)
				array[(n-1)-layer][(n-1)-layer-1-i] = cnt++;
				
				
			for(i=0; i < n-(layer*2) -2 ; i++)					//�� layer�� �׹�°	(������)(����)
				array[(n-1)-layer-1-i][layer] = cnt++;
				
				
			layer++;	//���� layer�� �̵� 
		}
	}
	
	printf("\n");		// ��� 
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%3d",array[i][j]);
			
		printf("\n");
	}
	
	return 0;
}















