bool IS_BST( BinTree T, int *min, int *max )
{ /* min �� max �� T �����н��ֵ���¡��Ͻ� */
     int lmin, lmax, rmin, rmax, Left_flag, Right_flag;
     
     if (!T) return true; /* �����϶���BST */
     if (!T->Left && !T->Right ) { /* ֻ��һ������� */
        (*min) = (*max) = T->Data; /* ���������Сֵ���Ǹ���ֵ */
        return true; /* ��������϶���BST */
     }

     Left_flag = Right_flag = false; /* ���������жϽ����ʼ�� */

     /* �ֱ��ж����������Ƿ���� */
     if ( (T->Left  && IS_BST(T->Left, &lmin, &lmax)  && T->Data > lmax)|| !T->Left )
            Left_flag = true;
     if ( (T->Right && IS_BST(T->Right, &rmin, &rmax) && T->Data < rmin)|| !T->Right )
            Right_flag = true;

     if (Left_flag && Right_flag){ /* ������߶����ԣ��������½� */
             if (T->Left)	(*min) = lmin;
             else			(*min) = T->Data;
             if (T->Right)	(*max) = rmax;
             else			(*max) = T->Data;
             return true;
     }
     else  return false;
}

bool IsBST ( BinTree T )
{
     int minT, maxT;
     
     minT = maxT = -1;
     return IS_BST( T, &minT, &maxT );
}

