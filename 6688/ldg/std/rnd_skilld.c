// rnd_skilld.c
//
// by meteoric

#define CLASSDIR "/class/"

string *force_skills=({});
string *parry_skills=({});
mapping weapon_skills=([]);
string *dodge_skills=({});

int make_skillmap( )
{
	int i,j,len;
	string *classname,*skillname,name,full_name;

	classname = get_dir(CLASSDIR);
	i = sizeof(classname);
	while(i--)
	{
		skillname=get_dir(CLASSDIR+classname[i]+"/skills/");
		j=sizeof(skillname);
		while(j--)
		{
                 // dongsw
        if (skillname[j]=="fuyu-sword.c"||skillname[j]=="taomo-dafa.c"||skillname[j]=="yijinjing.c")
         continue;
			len=sizeof(skillname[j]);
			if ( skillname[j][(len-2)..(len-1)]==".c" )
			{
				name=skillname[j][0..(len-3)];
				full_name=CLASSDIR+classname[i]+"/skills/"+name;
				if(full_name->valid_enable("force")) force_skills+=({name});
				if(full_name->valid_enable("parry")) parry_skills+=({name});
				if(full_name->valid_enable("dodge")) dodge_skills+=({name});
				if(full_name->valid_enable("sword")) weapon_skills+=([name:"sword"]);
				if(full_name->valid_enable("blade")) weapon_skills+=([name:"blade"]);
				if(full_name->valid_enable("cuff")) weapon_skills+=([name:"cuff"]);
				if(full_name->valid_enable("staff")) weapon_skills+=([name:"staff"]);
				if(full_name->valid_enable("spear")) weapon_skills+=([name:"spear"]);
				if(full_name->valid_enable("whip")) weapon_skills+=([name:"whip"]);
			}
		}
	}
	return 1;
}

string rnd_force()
{
	if( !stringp(force_skills) || !sizeof(force_skills) )  make_skillmap();
	return force_skills[random(sizeof(force_skills))];
}

string rnd_dodge()
{
	if( !stringp(dodge_skills) || !sizeof(dodge_skills) )  make_skillmap();
	return dodge_skills[random(sizeof(dodge_skills))];
}

string rnd_parry()
{
	if( !stringp(parry_skills) || !sizeof(parry_skills) )  make_skillmap();
	return parry_skills[random(sizeof(parry_skills))];
}

mapping rnd_weapon_skill()
{
	string *str1,skill_name;
	mapping rnd_skill=([]);
	if( !mapp(weapon_skills) || !sizeof(weapon_skills) )  make_skillmap();
	str1=keys(weapon_skills);
	skill_name=str1[random(sizeof(weapon_skills))];
	rnd_skill=([skill_name:weapon_skills[skill_name]]);
	return rnd_skill;
}
