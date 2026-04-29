
/**************************************************************************/
// 纵横巫师学校 
// ZHSCHOOL Contributed Source: From 1717
// $Id: gufeng.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("易挺", ({ "yiting" , "yi" }) );

        set("nickname", HIR"红鹰剑客"NOR);
        set("gender", "男性");
        set("age", 32);
        set("long",
                HIR"易挺,彩虹七剑之红鹰剑客。\n" NOR
                HIW"他武功高强，是武林中的后起之秀。\n" NOR
                HIW"他还未开山立派，且从不收徒弟。\n" NOR
            );
        set("title",HIY "彩虹七剑" NOR);
        set("attitude", "peaceful");

        set("inquiry", ([
                "分尸": "那个被分尸的弟子好象叫云铿，行刑的是铁中堂....。\n",
                "铁中堂": "听说他是铁血大旗门杰出的弟子，我怎么也不相信他会给云铿行刑.\n",
                "结婚": "听我妹妹说最近有人结婚。\n",
        ]) );

        set("str", 60);
        set("int", 24);
        set("cor", 60);
        set("cps", 30);
        set("per", 30);

        set("force", 20000);
        set("max_force", 10000);
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
                YEL"铁血大旗门的都是血性男儿。\n" NOR,
                HIR"听说有个铁血弟子被分尸了。真可惜\n" NOR ,               
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
        set_skill("hongying-jianfa",250);
        set_skill("hongying-force",200);
        set_skill("hongying-zhangfa",250);
        set_skill("hongying-shenfa",250);
        set_skill("sword",300);

        set_skill("buddhism", 200);

        map_skill("unarmed", "hongying-zhangfa");
        map_skill("force", "hongying-force");
       map_skill("dodge","hongying-shenfa");
       map_skill("sword","hongying-jianfa");
       map_skill("parry","hongying-jianfa");
        setup();
        carry_object("/d/moon/obj/rcloth")->wear();
        carry_object("/d/moon/obj/rsword")->wield();

}


