class Matrix
{
	public static void main(String args[])
	{
		int i,j,k,sum=0;
		int mat1[][]={{1,6,4},{1,2,2},{1,1,7}};
		int mat2[][]={{4,1,1},{6},{2}};
		int arow=mat1.length,acol=mat1[0].length,bcol=mat2[0].length,brow=mat2.length;
		int mat3[][]=new int[arow][bcol];
		if(acol!=brow)
		{
			System.out.println("Matrix multiplication is not posible");
			System.exit(0);
		}
		else
		{
			for(i=0;i<arow;i++)
			{
				for(j=0;j<bcol;j++)
				{
					for(k=0;k<acol;k++)
					{
						sum+=mat1[i][k]*mat2[k][j];
					}
					mat3[i][j]=sum;
					sum=0;
				}
			}
		}
		System.out.println("The given matrix A:");
		for(i=0;i<arow;i++)
		{
			for(j=0;j<acol;j++)
			{
				System.out.print(mat1[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("The given matrix B:");
		for(i=0;i<brow;i++)
		{
			for(j=0;j<bcol;j++)
			{
				System.out.print(mat2[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("The product of two matrices is ");
		for(i=0;i<arow;i++)
		{
			for(j=0;j<bcol;j++)
			{
				System.out.print(mat3[i][j]+" ");
			}
			System.out.println();
		}
	}
}
		
		
						
		
