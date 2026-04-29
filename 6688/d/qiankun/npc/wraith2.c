// wraith.c
#include <ansi.h>
inherit "/std/char/doomnpc";

//int is_ghost() { return 1; }

void create()
{
        set_name(HIB"幽冥游神"NOR, ({ "youming wraith","wraith" }) );
        set("long",
"一个披头散发，浑身是血的厉鬼，正在这里飘来飘去。\n"
"想不到乾坤教竟然可以控制鬼神来保护这个神秘的宝藏库。\n"
     );
        set("attitude", "friendly");
        set("max_gin", 4000);
        set("max_kee", 8000);                    
        set("max_sen", 1000);
        set("max_force",4000);
        set("force",8000);
        set("force_factor",200);
        set("bellicosity",500);
        set("cor",200);
        set("cps",200);

        set("chat_chance", 10);
        set("chat_msg", ({
//                (:random_move():),
           }) );



        set("combat_exp",20000000);

        set_skill("dodge", 250);
        set_skill("lingboweibu",250);
        set_skill("parry", 250);
        set_skill("move", 250);
        set_skill("liumai-shenjian", 250);
        set_skill("finger", 250);
        set_skill("beiming-shengong", 220);
        set_skill("force", 250);
        set_skill("douzhuanxingyi", 250);
        map_skill("parry","douzhuanxingyi");
        map_skill("dodge","lingboweibu");
        map_skill("move","lingboweibu");
        map_skill("force", "beiming-shengong");
        map_skill("finger", "liumai-shenjian");

        prepare_skill("finger", "liumai-shenjian");



        set("shen_type",-1);
        set("shen",-1000000);
        setup();
         set_temp("apply/armor_vs_force",300); 
         set_temp("apply/armor",300); 
        carry_object("/d/qiankun/obj/jincanwang");
        carry_object("/d/qiankun/obj/dragon_armor")->wear();
        carry_object("/class/mingjiao/obj/goldpao")->wear();

}

void init()
{
        object ob = this_player();
        
        ::init();

        if (interactive(ob) && ob->query("combat_exp")< 6000000)
        {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);  
        }       
}


