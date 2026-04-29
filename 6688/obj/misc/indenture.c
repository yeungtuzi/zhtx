// indenture.c
//written by tang

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;                             

string *special_props = ({
	"short", "long" });

int save_room_file(string );

void create()
{
        	set_name("房契", ({"indenture"}) );
        	set_weight(10);
        	set("no_get",1);
//        	set("no_drop","你的房契不能丢弃。\n");
        	if( clonep() )
                	set_default_object(__FILE__);
        	else 
	{
                	set("unit", "张");
                	set("material", "paper");
        	}
}

void init()
{
        	add_action("do_describe", "depict");
        	add_action("do_gohome", "gohome" );           
	add_action("do_invite", "invite");
}                                                                                  

int do_describe(string arg)
{                                             
	object me;

	me=this_player();
                                           
	if( file_name(environment(me))!=("/open/room/"+me->query("room/id")) )
		return notify_fail("请在自己家里施工!\n");

	if( !arg ) 	return notify_fail("指令格式：depict <房名>\n");
                                                                                                       
	environment(me)->set("short", arg);
	me->edit( (: call_other, __FILE__, "do_to", me ,arg:) );
	return 1;
}

int do_to(object me, string arg, string str)
{
	seteuid(getuid());                                            

	environment(this_player())->set("long", str);
	write("Ok.\n");
	return save_room_file(str);
}                             

int save_room_file(string arg)
{                                                                               
	object env;
	string str, *name, file;
	mapping prop;
	int i;

	seteuid(geteuid());

	env = environment(this_player());
	file = file_name(env) + ".c";
	str = "// Room: " + file + @ROOM_CODE


inherit ROOM;

void create()
{
ROOM_CODE
	;
	str += sprintf("\tset(\"short\", %O);\n", env->query("short") );
	str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", arg );
	prop = env->query_entire_dbase();
	name = keys(prop);
	for(i=0; i<sizeof(name); i++) {
		if( member_array(name[i], special_props)!=-1 ) continue;
		str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );
	}
	str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";

	// Indent structured constants with tab char
	str = replace_string(str, "\n  ", "\n\t\t");

	rm(file);

	if( write_file(file, str) ) 
	{
		write("Ok.\n");
		return 1;
	} 
	else	return notify_fail("你没有写入这个档案(" + file + ")的权利。\n");
}

int do_gohome()
{                        
	object me;        
	string arg;	
                                          
	me=this_player();

	if( !me->query("room/buy") )
		return notify_fail("你还没有家。\n");
	
	if( file_name(environment(me))!="/d/road/kaifeng" )
		return notify_fail("你家不在附近。\n");

	arg=me->query("room/id");
	if( file_size("/open/room/"+arg+".c") <1 )                         
	{
		me->delete("room/id");
		me->delete("room/buy");		
		tell_object(me,"你的家被毁了。\n");
		destruct(this_object());	         
		return 1;
	}

	message_vision("$N回家了。\n",me);
	me->move("/open/room/"+arg);
	me->apply_condition("room_tax",5000);
	message_vision("$N说道:「我回来啦。」\n",me);
	return 1;
}

int do_invite(string arg)
{                       
	object me,who,ob;                                       

	if( !arg )	return notify_fail("你要邀请谁？\n");
	
	me=this_player();

	if( !me->query("room/id") )	return notify_fail("你还没有家。\n");
                                              
	if( !(who=present(arg, environment(me))) )	return notify_fail("咦，有这个人吗？\n");      

	ob=new("/obj/misc/invitation");
	ob->set("roomid", me->query("room/id"));
	ob->move(who);
	tell_object(me, "已经把邀请信送到"+who->query("name")+"处啦!\n");
	tell_object(who, RED+me->query("name")+"邀请你去他家作客。\n"+NOR);
	return 1;
}

void owner_is_killed() 
{ 
	destruct(this_object()); 
}                                           

string query_autoload()
{
        object me;
        string target,cardname;

        me = this_player();
        cardname = present("indenture")->query("name");

        sscanf(cardname,"你和%s的房契" ,target);
      
        return target;
}

void autoload(string arg)
{
        set("name","你和"+arg+"的房契");
}

