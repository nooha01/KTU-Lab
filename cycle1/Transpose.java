	class Transpose
	{
		public static void main(String args[])
		{
			int i,j;
			int mat[][]={{1,1,1}};
			int row=1,col=3;
			System.out.println("The given matrix is");
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					System.out.print(mat[i][j]+" ");
				}
				System.out.println();
			}
			System.out.println("The transpose of the given matrix is ");
			for(i=0;i<col;i++)
			{
				for(j=0;j<row;j++)
				{
					System.out.print(mat[j][i]+" ");
				
				}
				System.out.println();
			}
		}
	}
		
