/**************************************************************************/
// $Id: shuilingguang.c,v 1.1 2000/12/14 15:21:45 cmy Exp $
/**************************************************************************/
// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_marry2();
void consider();

void create()
{
        set_name("新娘子", ({ "shui lingguang" , "shui" }) );

        set("nickname", HIR"结巴姑娘"NOR);
        set("gender", "女性");
        set("age", 21);
        set("long",
                "\n"
                HIG"她风华绝代，倾国倾城。\n" NOR
                HIG"她现在凤冠霞，一看就是新娘子的打扮。\n" NOR
                HIG"但是她看起来满腹心事，愁容满面。\n" NOR
            );
        set("title",HIY "闭月羞花" NOR);
        set("attitude", "peaceful");

        set("inquiry", ([
                "水灵光": "我现在烦着呢，离我远点。\n",
                "铁中堂": "我不要他当我哥哥。\n",
                "朱藻":"我只想当他妹妹\n",
        ]) );
//38
        set("per", 60);

        set("force", 10000);
        set("max_force", 5000);
        set("force_factor", 50);
       set("max_mana",5000);
       set("max_atman",5000);
        set("combat_exp", 6000000);
        set("score", 500000); 
       set("max_kee",5000);
       set("max_gin",5000);
       set("max_sen",5000);
       set("kee",5000);
       set("gin",5000);
       set("sen",5000);
//       set("attack",100);
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


