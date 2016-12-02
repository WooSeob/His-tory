///////////////////////
// 2016250033 변우섭 //
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
		if(layer == LastLayer) // 마지막 layer에 도달했을때 
		{
			if(n%2 == 1)	//홀수면 
			{
				array[n/2][n/2]=n*n; // 정중앙 원소를 n*n로 채우고 종료 
				break;
			}
			else			//짝수면 
			{
				for(i=LastLayer; i<= LastLayer+1; i++)	// -> 채우기 
					array[LastLayer][i] = cnt++;	
				for(i=LastLayer+1; i>= LastLayer; i--)	// <- 채우기 
					array[LastLayer+1][i] = cnt++;	
				break;
			}	
		}
		else
		{
			for(i=0; i < n-(layer*2)    ; i++)					//각 Layer의 시작(정방향)(상단)
				array[layer][i+layer] = cnt++;
			
			
			for(i=0; i < n-(layer*2) -1 ; i++)					//각 layer의 두번째 (정방향)(우측)
				array[i+layer+1][(n-1)-layer] = cnt++;
			
			
			for(i=0; i < n-(layer*2) -1 ; i++)					//각 layer의 세번째 (역방향)(하단)
				array[(n-1)-layer][(n-1)-layer-1-i] = cnt++;
				
				
			for(i=0; i < n-(layer*2) -2 ; i++)					//각 layer의 네번째	(역방향)(좌측)
				array[(n-1)-layer-1-i][layer] = cnt++;
				
				
			layer++;	//다음 layer로 이동 
		}
	}
	
	printf("\n");		// 출력 
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%3d",array[i][j]);
			
		printf("\n");
	}
	
	return 0;
}















