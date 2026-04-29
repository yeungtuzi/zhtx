//#pragma optimize all

#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
//#include "/adm/simul_efun/user.c"

// This must be after gender.c
#include "/adm/simul_efun/message.c"

void create()
{
	seteuid(getuid());
	write("simul_efun loaded successfully.\n");
}
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
