//NPC:/d/suzhou/npc/driver.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("阿牛", ({ "a chang", "chang" }) );
        set("title", HIW"镖局车夫"NOR);
        set("gender", "男性" );
        set("shen_type", 1);
        set("age", 30);
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);

        set("no_clean_up",1);

        set("long",
                "这是整天笑咪咪的年轻人，在镖局中负责驾车，虽然功夫不高，却也过得自在。\n" );
        set("combat_exp", 5000+random(5000));
        set("attitude", "peaceful");
        set("chat_chance", 1);
        set("chat_msg", ({
                "阿牛说道: 这位师兄，您想坐车赶路吗 ?\n",
        }) );

        set("max_kee", 300);
        set("max_gin", 200);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 10);
        set("shen_type", 1);
                              
        set_skill("force", 30); 
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        
        setup();
        
        carry_object("/obj/cloth.c")->wear();
}



