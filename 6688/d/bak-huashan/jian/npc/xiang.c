// xiang.c 向问天
#include <ansi.h>
inherit NPC;
int ask_help();
void create()
{
        set_name("向问天",({"xiang wentian","xiang"}));
        set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");  
	set("nickname", HIR "天王老子" NOR);
        set("long", 	
"他容貌清癯，颏下疏疏朗朗一丛花白长须，垂在胸前，手持酒\n"
"杯，眼望远处黄土大地和青天相接之所，对围着他的众人竟正眼\n"
"也不瞧上一眼。他背上负着一个包袱，再看他腰间时，却无弯刀\n"
"。原来他竟连兵刃也未携带。\n");
        set("gender", "男性");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("int", 50);
        set("con", 56);
        set("per", 25);
        set("max_kee", 4000);
        set("max_gin", 1000);
	set("max_sen", 1000);
	set("atman", 1000);
    	set("max_atman", 1000);
    	set("mana", 1000);
    	set("max_mana", 1000);
        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 200);
        set("combat_exp", 5000000);
        set("score", 40000);
        set_temp("apply/attack",50);
        set_temp("apply/defense",100);
        set_skill("force", 200);
        set_skill("tianmo-dafa", 200);
        set_skill("dodge", 200);
        set_skill("mo-shan-jue", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("mo-jian-jue", 200);
        set_skill("mo-zhang-jue", 200);
        set_skill("strike", 200);
	set_skill("move",200);
        set_skill("hammer",200);
	set_skill("mo-chui-jue",200);
	map_skill("move","mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
        map_skill("parry", "mo-chui-jue");
        map_skill("sword", "mo-jian-jue");
	map_skill("hammer","mo-chui-jue");
        prepare_skill("strike", "mo-zhang-jue");
        create_family("日月神教", 14 , "长老");
	set("inquiry", ([
                "帮助" : (: ask_help :),
		"help" : (: ask_help :),
        ]));
        setup();
        carry_object(__DIR__"obj/hua");
	carry_object(__DIR__"obj/zitie");
	carry_object(__DIR__"obj/qinpu");
	carry_object(__DIR__"obj/qipu");
        carry_object(__DIR__"obj/liaokao")->wield();
	carry_object("/d/huashan/obj/baishan")->wear();
        
}
int ask_help()
{
      object me;
      me = this_player();
      if (!me->query("marks/出游"))
	{
	  command("? "+me->name());
	  command("say 这位"+RANK_D->query_respect(me)+"无缘无故问我这个干什么？\n");
	  return 0;
	}
      if (me->query("combat_exp")<1000000)
	{
	  command("sigh");
	  command("hmm "+me->query("id"));
	  command("say 这位"+RANK_D->query_respect(me)+"你功夫不够，没法帮助老夫。\n");
          return 0;
	}
       command("smile");
       command("thank "+me->query("id"));
       command("say 既然这位"+RANK_D->query_respect(me)+"愿意襄助老夫，老夫不胜感激。\n");
       command("follow "+me->query("id"));
       return 0;
}