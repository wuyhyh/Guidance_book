Position Find( HashTable H, ElementType Key )
{
	Position CurrentPos, NewPos;

    /* 从散列地址开始 */
	NewPos = CurrentPos = Hash( Key, H->TableSize );
    /* 当单元不空但不是Key时 */
	while( H->Cells[NewPos].Info!=Empty && H->Cells[NewPos].Data!=Key ) {
        NewPos ++; /* 线性探测 */
	    if ( NewPos >= H->TableSize ) /* 表尾折返到表头 */
			NewPos -= H->TableSize;
           /* 如果回到出发地，说明表满了 */
	    if (NewPos == CurrentPos) return ERROR;
	}
	return NewPos; /* 此时或者遇到空单元，或者找到Key */
}

