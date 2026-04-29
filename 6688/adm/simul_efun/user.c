int interactive(mixed ob)
{
        if( !ob || !objectp(ob) ) return 0;
	return efun::interactive(ob);
}


int userp(mixed ob)
{
	if( !ob || !objectp(ob) ) return 0;
	return efun::userp(ob);
}
