/**************************************************************************/
// $Id: qiandahe.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("钱大河", ({ "qian dahe" , "qian" }) );

        set("nickname", YEL"黄冠剑客"NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
                HIR"钱大河,彩虹七剑之黄冠剑客。\n" NOR
                HIW"他是碧月剑客的丈夫\n" NOR
                "他一脸的麻子，和站在他身边的妻子极不相衬。\n"
            );
        set("title",HIY "彩虹七剑" NOR);
        set("attitude", "peaceful");

        set("str", 40);
        set("int", 30);
        set("cor", 40);
        set("cps", 50);
        set("per", 3);

        set("force", 12000);
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
                "钱大河恶狠狠的说道:一定要杀了那个狗杂种\n",
                YEL"你跟那姓沈的是怎么回事情？\n" NOR,
                YEL"你这个贱人，居然趁我不在的时候跟别的男人勾勾搭搭.\n" NOR,              
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
        set_skill("shuangfei-jianfa",250);
        set_skill("shuangfei-force",200);
        set_skill("shuangfei-zhangfa",250);
        set_skill("shuangfei-shenfa",250);
        set_skill("sword",300);

        set_skill("buddhism", 200);

        map_skill("unarmed", "shuangfei-zhangfa");
        map_skill("force", "shuangfei-force");
       map_skill("dodge","shuangfei-shenfa");
       map_skill("sword","shuangfei-jianfa");
       map_skill("parry","shuangfei-jianfa");
        setup();
        carry_object("/d/moon/obj/qcloth")->wear();
        carry_object("/d/moon/obj/qsword")->wield();

}


