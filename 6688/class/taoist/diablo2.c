#include <ansi.h>
inherit "/std/char/doomnpc";
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name(HIW"地狱"+HIR"圣火"NOR, ({ "diyu shenghuo", "diablo" }));
        set("nickname", HIC"笨蛋天师"NOR);
        set("long", "，很多高手命丧与此，茅山派因此而势微。他于是决心探索事实的真相，解破\n"
"这个数十年困扰茅山派的谜团，三年后，真相大白于天下，而武林中也诞生了\n"
"一位前无古人后无来者的绝世高手。据说他当时秘密做了一个档案，很多鲜为\n"
"人知的武林密史都记录在其中，你要想打听点什么消息可以先问问他。\n");

        set("gender", "男性");
        set("age", 35); 
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("cor", 100);
        set("int", 100);
        set("spi", 100); 

        set("cps", 100); 
        set("per", 100);
        set("con", 100);
        set("kar", 100);
        set("bln", 100);

        set("kee", 5000);
        set("max_kee", 5000);
        set("gin", 5000);
        set("max_gin", 5000);
        set("sen", 5000);
        set("max_sen", 5000);
        set("force", 8000);
        set("max_force", 4000);
        set("force_factor", 300);
        set("atman",8000); 
        set("max_atman", 8000);
        set("mana", 8000);
        set("max_mana", 4000);
        set("mana_factor", 150);
        set("combat_exp", 20000000);
        set("score", 200000);

        set("apprentice_available", 3);
        set_skill("literate", 300);
        set_skill("magic", 250);

        set_skill("force", 200);
        set_skill("spells", 250);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("gouyee", 200);
        set_skill("qingcheng-steps",200);
        set_skill("yueying-wubu",200);
        set_skill("necromancy", 250);
        set_skill("music", 161);
        set_skill("taoism", 250);
        set_skill("taosword", 200);
        set_skill("essencemagic", 200);
        set_skill("space", 200);

        map_skill("force", "gouyee");
        map_skill("sword", "taosword");
        map_skill("dodge", "qingcheng-steps");
        map_skill("move", "yueying-wubu");
        map_skill("parry", "taosword");
        map_skill("spells", "necromancy");
        map_skill("magic", "essencemagic");

        create_family("茅山派", 5, "弟子");
        set_temp("manashield",1);
        set_temp("apply/defense",1000);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);   


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :), 
                (: exert_function, "recover" :),
                (: exert_function, "concentrate" :),
        }) );        
        setup();

        carry_object(__DIR__"/d/qiankun/obj/weapon/anling")->wield();
}

