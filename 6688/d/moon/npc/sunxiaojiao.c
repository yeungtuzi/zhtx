/**************************************************************************/
// $Id: sunxiaojiao.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("孙小娇", ({ "sun xiaojiao" , "sun" }) );

        set("nickname", HIG"碧月剑客"NOR);
        set("gender", "女性");
        set("age", 30);
        set("long",
                HIR"孙小娇,彩虹七剑之碧月剑客。\n" NOR
                HIW"她武功高强，是武林中的后起之秀。\n" NOR
                HIW"她是黄冠剑客的妻子\n" NOR
            );
        set("title",HIY "彩虹七剑" NOR);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 24);
        set("cor", 40);
        set("cps", 40);
        set("per", 30);

        set("force", 14000);
        set("max_force", 7000);
        set("force_factor", 100);
       set("max_mana",10000);
       set("max_atman",10000);
        set("combat_exp", 7000000);
        set("score", 500000); 
       set("max_kee",8000);
       set("max_gin",5000);
       set("max_sen",5000);
       set("kee",8000);
       set("gin",5000);
       set("sen",5000);
//       set("armor_vs_force", 100);
//       set("armor", 100);
        set("env/wimpy", 10);
        
        set("chat_chance", 2);
        set("chat_msg", ({
                "孙小娇趁钱大河不注意，向你抛了个媚眼\n",
                RED"大河，我是无辜的，你再冤枉我我就去死给你看\n" NOR,
                RED"大河，我心中只有你一个.\n" NOR,              
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("perception", 200);
        set_skill("literate",200);
        set_skill("shuangfei-jianfa",230);
        set_skill("shuangfei-force",200);
        set_skill("shuangfei-zhangfa",230);
        set_skill("shuangfei-shenfa",230);
        set_skill("sword",250);

        set_skill("buddhism", 200);

        map_skill("unarmed", "shuangfei-zhangfa");
        map_skill("force", "shuangfei-force");
       map_skill("dodge","shuangfei-shenfa");
       map_skill("sword","shuangfei-jianfa");
       map_skill("parry","shuangfei-jianfa");
        setup();
        carry_object("/d/moon/obj/scloth")->wear();
        carry_object("/d/moon/obj/ssword")->wield();

}


