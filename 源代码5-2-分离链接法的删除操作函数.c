bool Delete( HashTable H, ElementType Key )
{
     Position P, t;
     Index Pos;
     
     Pos = Hash( Key, H->TableSize ); /* 计算散列值 */
     P = H->Heads+Pos; /* 指向对应链表的头结点 */
    /* 当P的下一个结点不是Key时 */
     while( P->Next && strcmp(P->Next->Data, Key) )
        P = P->Next; /* 逐一扫描链表 */
     if (!P->Next) return false; /* 如果直到表尾都没找到 */
     else { /* 找到了P的下一个结点是Key，删除之 */
          t = P->Next;
          P->Next = t->Next;
          free(t);
          printf("%s is deleted from list Heads[%d]\n", Key, Pos);
          return true;
     }
}

