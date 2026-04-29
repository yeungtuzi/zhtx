/**************************************************************************/
// $Id: yunkeng.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_marry2();
void consider();

void create()
{
        set_name("新郎官", ({ "zhu zao" , "zhu" }) );

        set("nickname", HIR"欢天喜地"NOR);
        set("gender", "男性");
        set("age", 37);
        set("long",
                "\n"
                HIG"他头上无冠，面如满月,气概高华。\n" NOR
                HIG"他穿着京城最有名刘二娘设计的服装。\n" NOR
                HIG"看起来甚为滑稽，但他却毫不为意。\n" NOR
                HIG"掩盖不住他满心的欢喜，看来不要轻易打搅他。\n" NOR
            );
        set("title",HIY "夜帝之子" NOR);
        set("attitude", "peaceful");

        set("inquiry", ([
                "水灵光": "她终于答应嫁给我了,多亏了二弟。\n",
                "铁中堂": "他是我二弟，这次多亏了他。我一定会好好照顾灵光的。\n",
                "再生草庐主人":"虽然不知道他是谁，但是我相信二弟的眼光不会差，他是个英雄\n",
                "结婚": (: ask_marry2 :),
        ]) );
//38
        set("str", 60);
        set("int", 60);
        set("cor", 60);
        set("cps", 60);
        set("per", 60);

        set("force", 30000);
        set("max_force", 15000);
        set("force_factor", 200);
       set("max_mana",10000);
       set("max_atman",10000);
        set("combat_exp", 8000000);
        set("score", 500000); 
       set("max_kee",10000);
       set("max_gin",5000);
       set("max_sen",5000);
       set("kee",10000);
       set("gin",5000);
       set("sen",5000);
       set("attack",100);
//       set("armor_vs_force", 100);
//       set("armor", 100);
        set("env/wimpy", 10);
        
        set("chat_chance", 2);
        set("chat_msg", ({
                YEL"只有天下的英雄，才配做糊涂大意之人。\n" NOR,
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("parry",200);
        set_skill("dodge",200);
//76
        set_skill("move",200);
        set_skill("perception", 200);
        set_skill("literate",200);
        set_skill("tie-steps",250);
        set_skill("yunhai-force",200);
        set_skill("ill-quan",250);

        set_skill("buddhism", 200);

        map_skill("unarmed", "ill-quan");
        map_skill("force", "yunhai-force");
        map_skill("dodge","tie-steps");
        map_skill("parry","ill-quan");
        setup();
        carry_object("/d/moon/obj/ykcloth")->wear();

}

string ask_marry2()
{
  object ob;
  ob=this_player();
  if(!ob->query("marks/help_persuade")) 
{
  return "say 今天是我和灵光的婚事，阁下若有兴致，可留下喝杯喜酒。\n";
}
/*
  kill ob;
  return "\n";
 */
 }


