// save.c

// 99/7/10 modified by yeung
// 原始数据损坏时自动从备份中恢复.

int save()
{
	string file;
 	int rc = 1;     
 
	if( stringp(file = this_object()->query_save_file()) ) {
		assure_file(file+ __SAVE_EXTENSION__);
//		seteuid(0);
//		rc = cp (file + __SAVE_EXTENSION__, (file + ".bak"));
		seteuid(getuid());
		if ( rc ) {
		    return save_object(file);
		}
	}
	return 0;
}

int restore()
{
	string file;
	int i;

	if( stringp(file = this_object()->query_save_file()) ) {
		if( (i= restore_object(file)) ) return i;
		//原始档案损坏
		else
		{
			file += ".bak";
                     if( file_size(file+".o")>0 ) //备份存在
			{
				i = restore_object(file);
				save();
				return i;
			}
			//备份不存在
			return 0;
		}
	}
	return 0;
}
