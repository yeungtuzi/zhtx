/**************************************************************************/
// $Id: yunkeng.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_yun();
string ask_marry();
void consider();

void create()
{
        set_name("再生草庐主人", ({ "master yun" , "master" }) );

        set("nickname", HIR"浴火重生"NOR);
        set("gender", "男性");
        set("age", 38);
        set("long",
                "\n"
                HIC"他风神飘逸，神清骨爽，端的有林下逸士之风。\n" NOR
                HIC"他笑容虽爽朗，但眼神中却又深藏着一分浓厚的忧郁。\n" NOR
                HIC"这两种神情又是断然不同，而此刻却又同具一身，教人一眼看去。\n" NOR
                HIC"便能觉出此人身世必有一段不平凡的遭遇。\n" NOR
            );
        set("title",HIY "隐士" NOR);
        set("attitude", "peaceful");

        set("inquiry", ([
                "云铿": (: ask_yun :),
                "铁中堂": (: ask_yun :),
                "铁血大旗门":(: ask_yun :),
                "结婚": (: ask_marry :),
        ]) );
//38
        set("str", 60);
        set("int", 60);
        set("cor", 60);
        set("cps", 60);
        set("per", 60);

        set("force", 30000);
        set("max_force", 15000);
        set("force_factor", 250);
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

string ask_yun()
{

  object ob;
  ob = this_player();
  if (!ob->query("marks/ask_mastertie"))
  {
    command("say 在下不知道你再说什么？不知阁下可有兴致同饮一杯?\n");
    return "让在下尽点地主之宜\n";
   }
  command("say 原来是二弟的朋友，我就是本应被家法处置的铁血大旗门的弟子云铿，为二弟所救，隐居在此.\n");
  return "我二弟现在可好？\n";
}

string ask_marry()
{
  object ob;
  ob=this_player();
  if(!ob->query("marks/help_persuade")) 
{
  command("say 一对江湖朋友正准备近日在此完婚，阁下若有兴致，可留下喝杯喜酒。\n");
  return "让在下尽点地主之宜\n";
}
  message("sys","你开始向草庐主人讲起刚才在盛存孝那里听到的故事。。。\n",users());
  message("sys","。。。。。。。。。。。。。。。。。。。。。。。。\n",users());
  message("sys","。。。。。。。。。。。。。。。。。。。。。。。。\n",users());
  message("sys","草庐主人只听得满头大汗\n",users());
  command("say 多亏兄台相告，在下差点犯下大错。二弟正是托我促成灵光和朱藻的婚事.\n");
  return "还得阻拦朱兄\n";
}

