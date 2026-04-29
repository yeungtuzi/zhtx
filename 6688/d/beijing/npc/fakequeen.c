// fakequeen.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIM"太后"NOR, ({ "qing queen","queen" }) );
	set("gender", "女性" );
	set("age", 43);
	set("long", @TEXT
她就是当今皇太后，一张圆圆的脸，身材丰满，端是个美人。
TEXT
	);
	set("combat_exp", 1300000);

        set("str", 24);
        set("con", 28);
        set("int", 27);
	set("shen_type", -1);
	set("no_get",1);
        set("attitude", "friendly");
        set_skill("dodge", 150);
	set_skill("strike",150);
	set_skill("parry", 100);
        set_skill("force", 100);
	set_skill("celestrike",150);
	map_skill("parry","celestrike");
	map_skill("strike","celestrike");
	prepare_skill("strike","celestrike");
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
	setup();
        add_money("gold", random(3));
        carry_object(__DIR__"obj/queencloth")->wear();
}



void init()
{
	object who;
	who=this_player();
	add_action("do_pull","pull");
	add_action("do_pull","open");
	add_action("do_pull","recover");
	::init();
	if( interactive(who) && !is_fighting() ) 
		{
		remove_call_out("greeting");
		}
	call_out("greeting", 1, who);

}
void greeting(object who)
{       object *inv;
	object room;
	int j;
	string name;
	who=this_player();
	inv=all_inventory(who);
	if(userp(who))
	{
	for(j=0;j<sizeof(inv);j++)
	{ name=inv[j]->query("id");
	  if(name=="taijian fu")
	 {
	  call_out("consider",1,who);
	  return ;
	  }
	}
	if(who->query("gender")=="女性")
	  call_out("consider",1,who);
	call_out("killhim",1,who);
	}
	return ;	
}
int consider(object who)
{       object room;
	who=this_player();
	room=load_object("/d/beijing/qqmen");	
	command("?");
        command("look "+who->query("id"));
	if(who->query("gender")=="女性")
	   command("say 你是那个宫的宫女？到这里有什么事？我不需要你服侍。\n");
	else
	{
        if(random(3))
         command("say 你是那个监的公公？ 到这里什么事？\n");
      else
	{command("say 不长眼的奴才，这是你能来的地方么？还不赶紧出去？\n");
	who->move(room);
	message_vision("$N灰溜溜地退了出来。\n",who);
	 message_vision("$N灰溜溜地退了出去。\n",environment(this_object()));
	}
	}
	return 1;
}
int killhim(object who)
{	object room;
	who=this_player();
	room=load_object("/d/beijing/bridge1");
	message_vision("太后一见到$N，脸色一楞，道：“大胆刁民，居然敢乱闯宫闱。\n"+
		       "\n来人那。。。”\n",who);
	message_vision("只见门外涌进一队侍卫，答声道：“奴才在！”\n",who);
	message_vision("太后道：“给我拉出金水桥外打五十大棍！”\n",who);
	message_vision("侍卫一拥而上，把$N架了出去。\n",who);
	who->set("eff_kee",who->query("eff_kee")/2+1);
	who->move(room);
	message_vision("$N被侍卫架出到金水桥，按在桥上乱棍打去。$N被打得昏了过去。\n",who);
	who->unconcious();
	return 1;
}
int do_pull(object who)
{       who=this_player();
	call_out("killhim",0,who);
	return notify_fail("");
}
