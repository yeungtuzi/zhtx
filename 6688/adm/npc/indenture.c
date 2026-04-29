// indenture.c
//written by tang

#include <ansi.h>
#include <skill.h>

inherit ITEM;
inherit F_AUTOLOAD;                             
//inherit F_CLEAN_UP;

string *special_props = ({
	"short", "long" });

int save_room_file(string );

void create()
{
        	set_name("房契", ({"indenture"}) );
        	set_weight(10);
//        	set("no_get",1);
        	set("no_drop","你的房契不能丢弃。\n");
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
	add_action("do_kickout", "kickout");
//        add_action("do_xuexi", "xuexi");
        add_action("do_xuexi", "huxue");
//改个命令，省得和宗师冲突,by masterall
	add_action("do_zuofan","zuofan");
	add_action("do_zuotang","zuotang");	
}                                                                                  

string get_room_file(object me)
{
	string arg;

	arg = me->query("room/id");   
	if( !stringp(arg) ) return "";
	return "/data/room/"+arg[0..0]+"/"+arg;	
}	                                       

int do_describe(string arg)
{                                             
	object me;

	me=this_player();
                                           
	if( file_name(environment(me))!=get_room_file(me) )
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
	environment(this_player())->save();
	write("Ok.\n");
	return 1;
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

	if( file_size(get_room_file(me)+".c") <1 )                         
	{
		me->delete("room/id");
		me->delete("room/buy");		
		tell_object(me,"你的家被毁了。\n");
		destruct(this_object());	         
		return 1;
	}

	message_vision("$N回家了。\n",me);
	me->move(get_room_file(me));
	me->apply_condition("room_tax",50000);
	message_vision("$N说道:「亲爱的，我回来啦。」\n",me);
	return 1;
}

int do_invite(string arg)
{                       
	object me,who,ob;                                       
	string cardname,target;

	if( !arg )	return notify_fail("你要邀请谁？\n");
	
	me=this_player();

	if( !me->query("room/id") )	return notify_fail("你还没有家。\n");

        cardname = present("indenture")->query("name");

        sscanf(cardname,"你和%s的房契" ,target);

	if( arg==me->query("id") )
		return notify_fail("你发神经，自己请自己去自己家作客。\n");

	if( arg==target )
		return notify_fail("你发神经，请自己的伴侣去作客。\n");

	if( !(who=present(arg, environment(me))) )	return notify_fail("咦，有这个人吗？\n");      

	ob=new("/obj/misc/invitation");
	ob->set("roomid", me->query("room/id"));
	ob->move(who);
	tell_object(me, "已经把邀请信送到"+who->query("name")+"处啦!\n");
	tell_object(who, RED+me->query("name")+"邀请你去他家作客。\n"+NOR);
	return 1;
}

int do_kickout(string arg)
{                       
	object me,who;                                       
        
	me=this_player();

//	if( wizardp(me) )	return 0;

	if( file_name(environment(me))!=get_room_file(me) )
		return notify_fail("这又不是你家，不要随便赶人!\n");

	if( !arg )	return notify_fail("你要赶谁出去？\n");

	if( arg==me->query("id") )	return notify_fail("你发神经，赶自己出门。\n");
	
	if( !(who=present(arg, environment(me))) )	return notify_fail("咦，有这个人吗？\n");      

	if( file_name(environment(me))==get_room_file(who) )
		return notify_fail("你发神经，居然赶你伴侣出门。!\n");

	message_vision(who->query("name")+"被$N赶出家门。\n",me);
	who->move("/d/road/kaifeng");
	message_vision("$N被"+me->query("name")+"赶出了家门。\n",who);
	return 1;
}


int do_xuexi(string arg)
{
	string skill, teacher, master;
	object me,ob;
	int master_skill, my_skill, gin_cost;
	int faith_need;

	me=this_player();

	if( me->is_busy() ) return notify_fail("你现在没有空！\n");
 
	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
		return notify_fail("指令格式：xuexi <技能> from <某人>\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character() || !userp(ob) )
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

	if( me->query("wife/id")!=teacher && me->query("husband/id")!=teacher )
	{
		return notify_fail( ob ->name() + "不是你的伴侣！\n" );
	}

	if( !me->query("marry_time") || !ob->query("marry_time") )
		return notify_fail("你们小两口的感情还不够深，不能互相传授武艺！\n");
        if( me->query("combat_exp") > ob->query("combat_exp")*2 )
                return notify_fail("你的伴侣江湖经验和你差太多了，你无法学到任何东西！\n");

	if( me->query("age")-me->query("marry_time") < 5 || 
		ob->query("age")-ob->query("marry_time") < 5 )
		return notify_fail("你们小两口的感情还不够深，不能互相传授武艺！\n");

	faith_need = SKILL_D(skill)->query_faith_req(me->query_skill(skill,1));
	if(faith_need < 250) faith_need = 250;
	if( me->query("marry_times") )
		faith_need += 250*(int)me->query("marry_times")-250;
	if(faith_need < 250) faith_need = 250;

	if( me->query("couple_faith")/40 < faith_need )
		return notify_fail("你们小两口的感情还不够深，不能互相传授武艺！\n");

	if( file_name(environment(me))!=get_room_file(me) )
		return notify_fail("请在自己家里传授武艺!\n");

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	if( (string)SKILL_D(skill)->type()=="martial" )
		return notify_fail("这项技能不能随便传授。\n");		
	
	if( !userp(ob) && !ob->accept_learn(me, skill) )
		return notify_fail(ob->name() + "不愿意教你这项技能。\n");

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你伴侣了。\n");

	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	gin_cost = 250 / (int)ob->query("int") + 250 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
	printf("你向%s请教有关「%s」的疑问。\n", ob->name(),
		to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("sen") > gin_cost/5 + 1 ) 
	{
		ob->receive_damage("sen", gin_cost/5 + 1);
	} 
	else 
	{
		write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}
		

	if( (int)me->query("gin") > gin_cost ) 
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
		{
			printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name() );
		} 
		else 
		{
			tell_object(ob,"你指导"+me->name()+"学习"+to_chinese(skill)+"。\n");
			printf("你听了%s的指导，似乎有些心得。\n", ob->name());
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query("int")));
		}
	} 
	else 
	{
		gin_cost = me->query("gin");
		write("你今天太累了，结果什麽也没有学到。\n");
	}

	me->receive_damage("gin", gin_cost );

	return 1;
}

int do_zuofan(string arg)
{
	string target=" ";
	object obj,me,lover;

	me=this_player();

	if( file_name(environment(me))!=get_room_file(me) )
		return notify_fail("还是在家里做饭吧，比较有气氛!\n");

	if( !arg )	return notify_fail("zuofan <饭名>\n");

	if( me->is_busy() ) return notify_fail("你现在没有空！\n");
 
	if( me->query("gender")=="男性" )
		target=me->query("wife/id");

	if( me->query("gender")=="女性" )
		target=me->query("husband/id");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg += NOR;
	arg = "*"+arg;

	if( !present(target,environment(me)) )
	{
		if( me->query("gin")<30 )
			return notify_fail("你太累啦，休息一下再做饭吧！\n");
		
		me->add("gin",-20);
		me->start_busy(2);

		obj=new("/obj/food/fan");
		obj->set("name",arg);
		obj->move(me);
	
		message_vision("$N作出了香喷喷的"+arg+"。\n",me);
		
		return 1;
	}

	lover=find_player(target);

	if( lover->is_busy() ) return notify_fail("你伴侣现在没有空！\n");
 
	if( me->query("gin")<30 )
		return notify_fail("你太累啦，休息一下再做饭吧！\n");
	if( lover->query("gin")<30 )
	{
		if( lover->query("gender")=="女性" )
			return notify_fail("你夫人太累啦，休息一下再做饭吧！\n");
		return notify_fail("你丈夫太累啦，休息一下再做饭吧！\n");		
	}
		
	me->add("gin",-20);
	me->start_busy(2);
	lover->add("gin",-20);
	lover->start_busy(2);

	obj=new("/obj/food/fan");
	obj->set("name",arg);
	obj->move(me);

	message_vision("$N和$n作出了香喷喷的"+arg+"。\n",me,lover);
		
	return 1;
}

int do_zuotang(string arg)
{
	string target=" ";
	object obj,me,lover;

	me=this_player();

	if( file_name(environment(me))!=get_room_file(me) )
		return notify_fail("还是在家里做饭吧，比较有气氛!\n");

	if( !arg )	return notify_fail("zuotang <饭名>\n");

	if( me->is_busy() ) return notify_fail("你现在没有空！\n");
 
	if( me->query("gender")=="男性" )
		target=me->query("wife/id");

	if( me->query("gender")=="女性" )
		target=me->query("husband/id");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg += NOR;
	arg = "*"+arg;

	if( !present(target,environment(me)) )
	{
		if( me->query("gin")<30 )
			return notify_fail("你太累啦，休息一下再做饭吧！\n");
		
		me->add("gin",-20);
		me->start_busy(2);

		obj=new("/obj/food/tang");
		obj->set("name",arg);
		obj->move(me);
	
		message_vision("$N煮出了一锅香喷喷的"+arg+"。\n",me);
		
		return 1;
	}

	lover=find_player(target);

	if( lover->is_busy() ) return notify_fail("你伴侣现在没有空！\n");
 
	if( me->query("gin")<30 )
		return notify_fail("你太累啦，休息一下再做饭吧！\n");
	if( lover->query("gin")<30 )
	{
		if( lover->query("gender")=="女性" )
			return notify_fail("你夫人太累啦，休息一下再做饭吧！\n");
		return notify_fail("你丈夫太累啦，休息一下再做饭吧！\n");		
	}
		
	me->add("gin",-20);
	me->start_busy(2);
	lover->add("gin",-20);
	lover->start_busy(2);

	obj=new("/obj/food/tang");
	obj->set("name",arg);
	obj->move(me);

	message_vision("$N和$n煮出了一锅香喷喷的"+arg+"。\n",me,lover);
		
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

