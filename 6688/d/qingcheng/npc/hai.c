#include <ansi.h>
inherit NPC;
string ask_me(object who);
void create()
{
        set_name("海公公", ({"hai gonggong","hai","gonggong"})  );
        set("gender", "无性" );
        set("age", 58);
        set("str", 20);
        set("cor", 27);
        set("cps", 25);
           
        set("long",@LONG
海公公在皇宫中得罪了别的权贵，只好从皇宫里逃了出来，流落
在江湖上。
LONG);
     
        set("combat_exp", 2000);
	set("shen_type",-1);     
        set("inquiry", ([
                "自宫" : (: ask_me :)
		        ]) );
        setup();
        add_money("silver", 10);
        carry_object("/obj/cloth")->wear();
     
}

void init()
 {
       add_action("do_accept","accept");
 }

int do_zigong(object who)
{
	object ob;

	who=this_player();
	message_vision(RED"海公公拿出一把小刀，往$N的跨下比划了一下，只见他一个手起刀落...\n\n\n",who);
	message_vision("$N [啊] 的一声惨叫......\n"NOR,who);
        who->set("gin",-1);
	who->set("gender","无性");

	if( ob=present("marrycard",who) )
		ob->detruct();
	if( ob=present("indenture",who) )
		ob->detruct();
	who->delete("wife");
	who->delete("room");
	who->delete("marry_time");

        command( "chat 嗨......");
	return 1;
}
int do_accept(string arg)
{	object who;
	who =this_player();
	if((string)arg!="yes")
	{	command( "sigh");
		who->delete_temp("marks/zigong");
		return 1;
	}
	else 
	message_vision(RED"$N狠下决心，大喊一声: 女玩家闭眼!!!接着把腰带一解...\n"NOR,who);
	who->set_temp("marks/zigong",0);
	call_out("do_zigong",1,who,0);
	return 1;
}


string ask_me(object who)
{
	who = this_player();
	if( (string)who->query("gender")=="女性" ) 
		 return "你一个女流，还问人家男人的隐私?\n";
 	if((string)who->query("gender")=="男性")		
	{   who->add_temp("marks/zigong",1); 
 	    return "你真的要自宫吗？考虑清楚了再答复我!"+MAG"(accept yes or no)\n"NOR;
	}
 	if((string)who->query("gender")=="无性")		
	 return "大家都一样，你又何必问那么多呢!\n";

	       
}

