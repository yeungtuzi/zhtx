// wraith.c
#include <ansi.h>
inherit "/std/char/doomnpc";

int is_ghost() { return 1; }

void create()
{
        set_name(HIB"千面罗刹鬼"NOR, ({ "wraith" }) );
        set("long",
"一个披头散发，浑身是血的厉鬼，正在这里飘来飘去。\n"
"想不到乾坤教竟然可以控制鬼神来保护这个神秘的宝藏库。\n"
     );
        set("attitude", "aggressive");
        set("max_gin", 2000);
        set("max_kee", 4000);                    
        set("max_sen", 2000);
        set("max_force",4000);
        set("force",8000);
        set("force_factor",150);
        set("bellicosity",5000000);
        set("cor",30);
        set("combat_exp",5000000);

        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("fall-steps",200);
        set_skill("parry", 180);
        set_skill("move", 300);
        set_skill("sword",180);
        set_skill("fuliu-jian",180);

        map_skill("sword","fuliu-jian");
        map_skill("parry","fuliu-jian");
        map_skill("dodge","fall-steps");
        map_skill("move","fall-steps");

        set_temp("apply/attack",50);

        set("chat_chance_combat",5);
        set("chat_msg_combat", ({
                "留..下..尔..的..狗..命..来...\n",
        }) );

        set("shen_type",-1);
        set("shen",-1000000);
        setup();

        carry_object("/d/qiankun/obj/fakexiaolou")->wield();

}

