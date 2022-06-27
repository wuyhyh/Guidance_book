bool Delete( HashTable H, ElementType Key )
{
     Position P, t;
     Index Pos;
     
     Pos = Hash( Key, H->TableSize ); /* ����ɢ��ֵ */
     P = H->Heads+Pos; /* ָ���Ӧ�����ͷ��� */
    /* ��P����һ����㲻��Keyʱ */
     while( P->Next && strcmp(P->Next->Data, Key) )
        P = P->Next; /* ��һɨ������ */
     if (!P->Next) return false; /* ���ֱ����β��û�ҵ� */
     else { /* �ҵ���P����һ�������Key��ɾ��֮ */
          t = P->Next;
          P->Next = t->Next;
          free(t);
          printf("%s is deleted from list Heads[%d]\n", Key, Pos);
          return true;
     }
}

