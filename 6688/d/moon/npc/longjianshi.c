/**************************************************************************/
// $Id: longjianshi.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("龙坚石", ({ "long jianshi" , "long" }) );

        set("nickname", BLU"墨龙剑侠"NOR);
        set("gender", "男性");
        set("age", 35);
        set("long",
                HIR"龙坚石,彩虹七剑之墨龙剑侠。\n" NOR
                HIW"他武功高强，是武林中的后起之秀。\n" NOR
                HIW"他是蓝凤剑客的丈夫\n" NOR
            );
        set("title",HIY "彩虹七剑" NOR);
        set("attitude", "peaceful");

        set("str", 60);
        set("int", 60);
        set("cor", 50);
        set("cps", 50);
        set("per", 30);

        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 100);
       set("max_mana",10000);
       set("max_atman",10000);
        set("combat_exp", 7500000);
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
                HIM"栖梧，等了结了这段公案，我们就退出江湖\n" NOR,
                MAG"栖梧，我们也该要个孩子了.\n" NOR,              
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
        carry_object("/d/moon/obj/l2cloth")->wear();
        carry_object("/d/moon/obj/l2sword")->wield();

}


