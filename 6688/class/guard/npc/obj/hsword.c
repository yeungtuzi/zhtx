//OBJ:/d/xueshan/npc/obj/hsword.c
//by tlang for 混世神剑

#include <weapon.h> 
#include <ansi.h>
//#include <command.h>

#include <globals.h>
#ifndef SWORDDATA
#define SWORDDATA "/data/weapon/sword/"
#endif
#define HUNSWORD SWORDDATA + "hunsword"

inherit SWORD;
inherit F_UNIQUE;
inherit F_AUTOLOAD;
inherit F_SAVE;

void do_check();
void checking();
void go_back();
int goaway();
int dest();

int query_autoload()
{
	object dest=this_object()->query("my_master");

	if( this_player()->query("id") ==dest  )
                return 1;
        return 0;
}

string *start_loc = ({
        "/d/snow/inn",
        "/d/guanwai/inn",
        "/d/cloud/tearoom",
        "/d/jingcheng/jiuguan",
        "/d/yueyang/kedian",
	"/d/suzhou/kezhan",
});

string query_save_file()
{
	return HUNSWORD;
}

void create()
{
	set_name(HIW"混世神剑"NOR, ({ "hun sword", "sword" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",  "千古神器，得之不易。\n");
		set("value", 999999);
		set("material", "crimson gold");
		//set("replica_ob", "/obj/longsword");
	}

	init_sword(150);
	setup();
//	call_out("dest",12*86400);
//this line is for testing 
//	call_out("dest",600);
}

void init()
{
	add_action("do_get","get");
	add_action("do_give","give");
	add_action("do_wield","wield");
	add_action("do_unwield","unwield");
	add_action("do_pray","pray");
	add_action("do_detect","detect");
	add_action("do_study","study");
//	add_action("do_pawn","pawn");
//	add_action("do_sell","sell");
	remove_call_out("do_check");
	call_out("do_check",1);	
}

//this is for sword_master to destruct this sword when time comes.
int dest()
{
	if(!environment(this_object()) )
	{
		destruct(this_object());
		return 1;
	}
	message("system",
		HIR "\n你看见天空中一道闪电化过 ....\n\n"
		MAG	"江湖中人都知道：" HIR "混世神剑要\n\n"
			"\t\t重新出世了！！！！！！！！！！ ！\n\n" NOR,users() );
	destruct(this_object());
		return 1;
}

void do_check()
{	
	object me,ob,dest;

	me=this_object();
	ob=this_player();
//	dest = find_player(me->query("my_master"));

	if(!environment(ob) || environment(ob)!=environment()
|| !environment(ob)->query("my_hsword") )	
	{
		tell_object(ob,"sigh\n");
		return;
	}
	if(me->query("been_owned") && ob->query("id")!=me->query("my_master") )
	{	
		tell_object(ob,"sorry\n");
		return;	
	}
/*	if(ob->query("id")!=dest )
	{
		tell_object(ob,"waggle\n");
		return;
	}
*/
	tell_object(ob,"gonxi\n");
	set("name",ob->query("name")+HIW"的混世神剑"NOR);
	set("my_master",ob->query("id"));
	set("master_name",ob->query("name"));
	set("been_owned",1);
	save();
	//ob->delete("my_owner");
	call_out("checking",120);
}

void checking()
{
	object me;
	
	me=this_object();
	if(environment(me)->query("my_master") )
	{
		message("vision","he is on his master\n",environment(me));
		call_out("checking",120);
			return;
	}
	message("vision","hello",environment(me) );
	call_out("go_back",1);
	call_out("checking",120);
}

void go_back()
{
	object me,dest;
	
	me=this_object();
	dest = find_player(me->query("my_master"));
	
	if( !dest )
		return;
	if( environment(me)==dest )
		return;
	tell_object(dest,"the sword comes back.\n");
	me->move(dest);
}

int do_get(string arg)
{
	object me=this_object();
	object ob=this_player();
//	object dest=find_player(me->query("my_master"));

	if(!arg || arg!=me->query("id") )
		return notify_fail("你要拿什么？\n");	
	if(ob->query("id")!=me->query("my_master") )
		return notify_fail("这把剑拿不起来。\n");
	write("神剑突然飞入$N的手中。\n",ob);
	me->move(ob);
		return 1;
}


void do_give()
{

}

void do_wield(string arg)
{
	object me,ob,dest;
		
	me=this_object();
	ob=this_player();
	//dest=find_player(me->query("my_master"));
	
	if(ob->query("weapon_prop") )
	{
		tell_object(ob,"你已经装备有武器了。\n");
		return;
	}
	if(!arg || arg=="")
	{
		tell_object(ob,"你想装备什么作为武器？\n");
			return;
	}
	if(ob->query("id")!=me->query("my_master") )
	{
		set_name("破剑",({"po jian","jian","sword"}));
		set("long","一把破破的长剑。\n");
		set_weight(3000);
		set("value",1000);
		me->unwield();
		tell_object(ob,"一把破到这样的剑怎么能装备上呢？正装备着慌的剑摔到地上。\n");
		call_out("goaway",1);	
			return;
	}
	set("wield_msg", YEL"只见$N长叹一声，无可奈何地从空中把出一把混世神剑。\n" NOR);
	set("unwield_msg", HIW"$N一把将混世神剑掷入地下，禁不住潸然泪下。\n" NOR);
	set("weapon_prop/courage", 20);
	set("weapon_prop/intelligence", 25);
	set("weapon_prop/personality", 20);
	//set("rigidity", 40);
	ob->wield(me);
}	
 
int goaway()
{
	object me=this_object();
	object ob=this_player();

	me->move(environment(ob));
}

void do_unwield()
{}

int do_detect()
{}

//this is for sword_master to move 
int do_pray(string arg)
{
	object me=this_object();
	object ob=this_player();
	int mysen,damage;
	string startroom;	

	if(arg!="tlang")
		return notify_fail("what do you want to do?\n");
	if(!ob->query("my_master") )
		return notify_fail("you prayed,but nothing happened.\n");
	if(!me->query("weapon_prop") || !me->query("equipped") )
		return notify_fail("you havent wield the sword.\n");
	if(ob->query("sen")<=99 )
		return notify_fail("you are so tired\n");
	mysen =  (int)ob->query("sen");
	damage = random(5)+mysen*3/10;
	ob->receive_damage("sen",damage);	
	tell_object(ob,"good thing happened.\n");
	startroom = start_loc[random(sizeof(start_loc))];  
	ob->move(startroom);   
		return 1;  
}
//this is for sword_master to study sword
int do_study()
{}

/*int do_pawn(string arg)
{
	write("这种宝贝哪能随便pawn.\n");
		return 1;
}

int do_sell(string arg)
{
	write("这种宝贝哪能随便sell.\n");
		return 1;
}
*/
