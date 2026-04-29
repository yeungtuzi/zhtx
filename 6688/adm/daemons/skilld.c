// skilld.c
//
// This is the "daemon dispatcher" that provide a link to varius skill
// daemons.

#define CLASSDIR "/class/"
mapping skill_daemons = ([]);

int make_skillmap( )
{
	int i,j,len;
	string *classname,*skillname,name;

	classname = get_dir(CLASSDIR);
	i = sizeof(classname);
	while(i--)
	{
		skillname=get_dir(CLASSDIR+classname[i]+"/skills/");
		j=sizeof(skillname);
		while(j--)
		{
			len=sizeof(skillname[j]);
			if ( skillname[j][(len-2)..(len-1)]==".c" )
			{
				name=skillname[j][0..(len-3)];
				skill_daemons[name]=CLASSDIR+classname[i]+"/skills/"+name;
			}
		}
	}
	return 1;
}

string query_skill_daemon(string skill)
{
	if( !mapp(skill_daemons) || !sizeof(skill_daemons) )  make_skillmap();
	if( !undefinedp(skill_daemons[skill]) ) return skill_daemons[skill];
	return "/daemon/skill/" + replace_string(skill, " ", "_");
}