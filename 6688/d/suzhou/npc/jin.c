//by tlang
         
#include <ansi.h>
#ifndef BLADEDATA
#define BLADEDATA "/data/weapon/hsword/blade/"
#endif

inherit NPC;            

string ask_story();
string ask_blade();
void clone_blade(object ob,int stage);
int accept_object(object who, object what);

string *clone_msg=({
	"金老先生呵呵笑道：“ \n",
	"这把利刃在我这儿已久，早想送出去，\n",
	"只是一直找不到合适的人选。\n",
	"你帮了我大忙，我可以把它当作礼物送给你。”\n",
	"说完，他拿出一把寒光四射的形似长剑的刀来。\n",
	"“但你得先发一个誓来，不得把这秘密告诉别人。”\n",
});	

void create()
{
	set_name("金庸", ({ "jin yong", "jin" }));
	set("long", "金先生被称为当世第一大小说家，我们能在这儿玩mud，
得他小说之力甚多，他身上仿佛藏着许多秘密。\n");
	set("title",YEL"静心居士"NOR);

	set("gender", "男性");
	set("per", 23+random(10));      
	set("int", 30);
        set("age",55);
    
	set_skill("literate", 250);
	set_skill("leadership", 250);

	set_skill("iron-cloth",300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 50);

	set("max_force",1500);
	set("force",1500);
	set("max_mana",1000);
	set("mana",1000);
	set("max_atman",1000);
	set("atman",1000);

	set("combat_exp", 3000000);
	set("shen_type", 1);        
	set("inquiry", ([
		"小说" : (: ask_story :),	
		"story" : (: ask_story :),
		"邪剑穿灵" : (: ask_blade :),
		"blade" : (: ask_blade :),
	]));   
	set("count", 2);
	set("trigger",1);
	setup();
        
	add_money("gold", 10);
	carry_object(__DIR__"obj/jchmap");
	carry_object("/d/suzhou/npc/obj/zishan")->wear();
}                                   

void init()
{
	add_action("do_swear","swear");
	add_action("give_talk", "talk"); 
}

string ask_story()
{
	tell_object(this_player(),"我的小说本来被知府杨康抢去，如果你能帮我找回来，
我绝对不会亏待你的。\n");
	return "呵呵。。。。\n";
}                             

string ask_blade()
{
	if(query("trigger")<1) 
		return "已经有人帮我把书找齐了，下次再来吧。\n";
	if(!this_player()->query("can_ask") )
		return "你想知道这个问题，先帮我找全我的小说吧。\n";
	remove_call_out("clone_blade");
	call_out("clone_blade",2,this_player(),0);
	return "呵呵。。。。。。\n";
}

void clone_blade(object ob,int stage)
{
	tell_object(ob,clone_msg[stage]);
        if( ++stage < sizeof(clone_msg) )
        {
        call_out("clone_blade", 2, ob, stage );
                return;
        }
	ob->set_temp("can_swear",1);
}

int do_swear(string arg)
{
	object ob,obj,what;
	string newfile,filename,id;

	ob=this_player();
	
	if(!arg)	return notify_fail("你要发什么誓？\n");
	if(!ob->query_temp("can_swear") )
		return notify_fail("你这是干什么呀？\n");
	message_vision("$N发誓道：" + arg + "\n", ob);
	if( strsrch(arg, "守") >=0 && strsrch(arg, "秘密") >=0
	&&	strsrch(arg, "不") <0)
	{
		if( objectp( what=present("lighting blade",ob) ) )
		{	
		tell_object(ob,"你已经得到过一把邪剑穿灵了，太贪心了吧？\n");
			return 1;
		}

		id=ob->query("id");	
		newfile = read_file("/d/xueshan/npc/obj/xblade.c");
		newfile = replace_string( newfile, "no_owner", id);
		filename = BLADEDATA+id+".c";
		if(!write_file(filename, newfile,1))
		{
			tell_object(ob,"你没有写入这个文件的权力。\n");
				return 1;
		}
		command("smile");
		add("trigger",-1);
		ob->delete_temp("can_swear");
		ob->delete("can_ask");
		obj = new(filename);
		obj->move(ob);	
			return 1;
	}
	return notify_fail("你发的什么誓？恐怕不对吧？呵呵\n");
}

int give_talk(string arg)
{       
	object me=this_object();
        object who = this_player();

	if(!arg || arg!=me->query("id") )
	{
		tell_object(who,"你要和谁说话？\n");
			return 1;
	}
        if (query("count") < 1)
	{
		tell_object(who,"今天我已经累了，明天再来吧。\n");
                return command("sigh");
        }
	if(who->query("book1_given") && who->query("book2_given")
&& who->query("book3_given") && who->query("book4_given") && who->query("book5_given")
&& who->query("book6_given") && who->query("book7_given") && who->query("book8_given")
&& who->query("book9_given") && who->query("book10_given") && who->query("book11_given")
&& who->query("book12_given") && who->query("book13_given") && who->query("book14_given") )
	{
		command("smile");
		command("say 你很好，帮我找齐了十四本小说，我允许你向我打听一个秘密。\n");
		who->delete("book1_given");
		who->delete("book2_given");
		who->delete("book3_given");
		who->delete("book4_given");
		who->delete("book5_given");
		who->delete("book6_given");
		who->delete("book7_given");
		who->delete("book8_given");
		who->delete("book9_given");
		who->delete("book10_given");
		who->delete("book11_given");
		who->delete("book12_given");
		who->delete("book13_given");
		who->delete("book14_given");
		who->set("can_ask",1);
			return 1;
	}
	add("count", -1);
	command("sigh");
	command("say 老夫当年写下十四本书，不想现在一本也没有了，想来好不伤心。\n");
 	       return 1;
}

int accept_object(object who, object what)
{
	if(userp(what) )
		return notify_fail("金庸皱眉道：“你竟然敢拿玩家来给我？！\n");
	if( (string)what->query("id")=="heroes of eagle" )
	{
		command("pat "+who->query("id"));
		command("say 《射雕》拿来了，做的不错，继续努力。\n");
		who->set("book1_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="stories of city" )
	{
		command("pat "+who->query("id"));
		command("say 《连城诀》拿来了，做得不错，继续努力。\n");
		who->set("book2_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="couple blades" )
	{
		command("pat "+who->query("id"));
		command("say 《鸳鸯刀》拿来了，做得不错，继续努力。\n");
		who->set("book3_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="blood sword" ) 
	{
		command("pat "+who->query("id"));
		command("say 《碧血剑》拿来了，做得不错，继续努力。\n");
		who->set("book4_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="flying fox" )
	{
		command("pat "+who->query("id"));
		command("say 《雪山飞狐》拿来了，做得不错，继续努力。\n");
		who->set("book5_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="stories of fox" ) 
	{
		command("pat "+who->query("id"));
		command("say 《飞狐外传》拿来了，做得不错，继续努力。\n");
		who->set("book6_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="heroes of heroes" )
	{
		command("pat "+who->query("id"));
		command("say 《笑傲江湖》拿来了，做得不错，继续努力。\n");
		who->set("book7_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="couple heroes of eagle" )
	{
		command("pat "+who->query("id"));
		command("say 《神雕侠侣》拿来了，做得不错，继续努力。\n");
		who->set("book8_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="white horse in wind" )
	{
		command("pat "+who->query("id"));
		command("say 《白马啸西风》拿来了，做得不错，继续努力。\n");
		who->set("book9_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="stories of gods" )
	{
		command("pat "+who->query("id"));
		command("say 《天龙八部》拿来了，做得不错，继续努力。\n");
		who->set("book10_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="stories of heroes" )
	{
		command("pat "+who->query("id"));
		command("say 《书剑》拿来了，做得不错，继续努力。\n");
		who->set("book11_given",1);
		destruct(what);
			return 1;
	}	
	if( (string)what->query("id")=="stories of killing dragon" )
	{
		command("pat "+who->query("id"));
		command("say 《倚天屠龙记》拿来了，做得不错，继续努力。\n");
		who->set("book12_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="stories of emperor" )
	{
		command("pat "+who->query("id"));
		command("say 《鹿鼎记》拿来了，做得不错，继续努力。\n");
		who->set("book13_given",1);
		destruct(what);
			return 1;
	}
	if( (string)what->query("id")=="a wonderer" )
	{
		command("pat "+who->query("id"));
		command("say 《侠客行》拿来了，做得不错，继续努力。\n");
		who->set("book14_given",1);
		destruct(what);
			return 1;
	}
	return notify_fail("金说道：“这些不是我要的东西，我只要我的小说。呵呵”\n");
}
