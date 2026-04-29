// clean_up.c
// by Annihilator@ES2

int clean_up()
{
	object *inv;
	int i;

	// CLEANUP副本是应该的
	// 如果连master object也cleanup了有点。。。。得不偿失
	// 现在内存没有那么紧张了。
	// YEUNG 2000-3-29
	
	 if( !clonep() && this_object()->query("no_clean_up") ) return 1;
	//if( !clonep() ) return 1;
	if(interactive(this_object())) return 1;

	// If we are contained in something, let environment do the clean
	// up instead of making recursive call. This will prevent clean-up
	// time lag.
	if(environment()) return 1;

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
		if(interactive(inv[i])) return 1;

	destruct(this_object());
	return 0;
}
