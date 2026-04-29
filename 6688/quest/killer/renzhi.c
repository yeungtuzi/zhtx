#include <ansi.h>
inherit NPC;

void set_hp();
void create()
{
        set_name("朝廷大员" , ({ "ren zhi"}) );
        set("title", YEL"人质"NOR);
        set("long","这位是被乾坤教绑架的朝廷命官。\n");
        set("gender", "男性");
        set("taskkiller", 1);
        set("age", 20+random(10));
        set_skill("force", 200);
//        set_skill("taiji-shengong", 200);
        set_skill("taiji-shengong", 250);//原先好像是面了点，加强下吧
        set_skill("move", 300);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");
        setup();
}

void die()
{
        object ob = this_object();
        object me = ob->query("owner_player");
        object obj = ob->query("owner");

        message_vision(HIR"\n$N喊道：老子还有正事要办，不陪你玩了！\n"NOR,obj);
        me->delete("cttask/get");
        me->set("cttask/fail",1);
        destruct(obj);
        ::die();
}

void set_hp()
{
        object ob = this_object();
        object obj = ob->query("owner");
        int max_kee,max_gin,max_sen,skill_force,max_force,maximum_force,exp;

        max_kee = obj->query("max_kee");
        max_gin = obj->query("max_gin");
        max_sen = obj->query("max_sen");

        skill_force = obj->query_skill("force");
        max_force= obj->query("max_force");
        maximum_force = obj->query("max_force");
        exp = obj->query("combat_exp");

        //朝廷的人应该弱些
        set("max_force", max_force/2);
        set("force", max_force);
        set("force_factor", skill_force/4);
        set("max_kee", max_kee/2);
        set("eff_kee", max_kee/2);
        set("max_gin", max_gin/2);
        set("eff_gin", max_gin/2);
        set("max_sen", max_sen/2);
        set("eff_sen", max_sen/2);
        set("sen", max_sen/2);
        set("kee", max_kee/2);
        set("gin", max_gin/2);
        set("combat_exp", exp/2);
}

