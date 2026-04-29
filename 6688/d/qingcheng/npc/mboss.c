/*maid_boss.c*/
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("酒店女老板", ({"maid boss","boss"}));
        set("gender", "女性" );
        set("age", 34);
        set("str", 10);
        set("cor", 18);
        set("per", 27);
	set("shen_type",-1);
	 set("attitude", "friendly");
      
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 40);

       
        set("long",@LONG
她长得颇有几分姿色,酒店在她的协作下,搞得整整有条。
LONG);

       

        set("combat_exp", 100000);
//        set("score", -4000);

        set("chat_chance_combat", 60);

        set_skill("unarmed", 70);
        set_skill("dodge", 100);
        set_skill("force", 20);
        set_skill("qingcheng-steps", 60);

        set_skill("cuixin-zhang", 40);

      map_skill("unarmed", "cuixin-zhang");
      map_skill("dodge", "qingcheng-steps");
     
      set("inquiry", ([
                "订筵席" : "嗯!你这种无名小卒也配在这里订筵席?\n",
               
        ]) );

        setup();
        add_money("silver", 35);
        carry_object(__DIR__"obj/pink")->wear();
      
}
void init()
{
        add_action("do_gogo", "go");
        add_action("do_up", "up");
}

int do_gogo(string arg)
{
        if( arg == "up" )
        {
            write(MAG"女老板微微一笑，拦住了你的去路。说道：那是贱妾的卧室，请不要乱闯 。\n"NOR);
            return 1;
        }
        return 0;
}
int do_up()
{  write(MAG"女老板微微一笑，拦住了你的去路。说道：那是贱妾的卧室，请不要乱闯 。\n"NOR);
            return 1;
}
