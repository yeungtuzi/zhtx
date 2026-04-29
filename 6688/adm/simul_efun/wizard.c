// wiz.c

string wizhood(mixed ob)
{
	return (string)SECURITY_D->get_status(ob);
}

int wiz_level(mixed ob)
{
	return (int)SECURITY_D->get_wiz_level(ob);
}
                    
int raw_wiz_level(mixed ob)
{
	return (int)SECURITY_D->get_raw_wiz_level(ob);
}

string raw_wizhood(mixed ob)
{
	return (string)SECURITY_D->get_raw_status(ob);
}
                    
