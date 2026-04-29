inherit NPC;
#include <ansi.h>
void set_hp();

void create()
{
        set_name("乾坤判徒", ({ "qiankun betrayer"}));
        set("long", "他是一名背叛乾坤教的人，他渴望没有血腥的生活。\n");
        set("gender", "男性");
        set("age", 20+random(20));
        set("title",HIY"叛徒"NOR);
        set_skill("force", 300);
        set_skill("taiji-shengong", 300);
        set_skill("move", 300);
        set_skill("dodge", 300);
        set_skill("tiyunzong", 300);
        set_skill("cuff", 300);
        set_skill("taiji-quan", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("taiji-jian", 300);
        set_skill("taoism", 300);
        set_skill("literate", 300);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        setup();

}
void set_hp()
{
        object ob = this_object();
        object fighter = ob->query("fighter");
        int max_kee,max_gin,max_sen,skill_force,max_force,maximum_force,exp;

        max_kee = fighter->query("max_kee");
        max_gin = fighter->query("max_gin");
        max_sen = fighter->query("max_sen");

        skill_force = fighter->query_skill("force");
        max_force= fighter->query("max_force");
        maximum_force = fighter->query("max_force");
        exp = fighter->query("combat_exp");
        //叛徒应该比追杀者弱些
        set("max_force", max_force*2/3);
        set("force", max_force*4/3);
        set("force_factor", skill_force/3);
        set("max_kee", max_kee*2/3);
        set("eff_kee", max_kee*2/3);
        set("max_gin", max_gin*2/3);
        set("eff_gin", max_gin*2/3);
        set("max_sen", max_sen*2/3);
        set("eff_sen", max_sen*2/3);
        set("sen", max_sen*2/3);
        set("kee", max_kee*2/3);
        set("gin", max_gin*2/3);
        set("combat_exp", exp*2/3);
}

void init()
{
          object ob,me=this_object();
          ::init();
          if( interactive(ob = this_player()) && !is_fighting()
                  && ob->query("cttask/var") == "劝架" && me->query("var") == "劝架"
                  && me->query("owner") == ob)
          {
                  remove_call_out("fighting");
                  call_out("destroy_ob", 360, me);
                  call_out("fighting", 1, ob);
          }
}
void fighting(object ob)
{
        object me = this_object();
        object obj = me->query("fighter");
        message_vision(HIG"\n$N大叫到：我已经厌倦这种血腥的生活了，你们又为何苦苦相逼呢？\n"NOR,me);
        message_vision(RED"\n$N冷笑到：你还记不记得教主当年立下的教规？" HIR "  判教者死！\n"NOR,obj);
        me->kill_ob(obj);
        obj->kill_ob(me);
}
void destroy_ob(object ob)
{
        object obj = ob->query("fighter");
        message_vision(HIG"\n$N“蹭”的一声不见踪影了。\n"NOR,ob);
        call_out("destroy_obj", 1, obj,ob);
}
void destroy_obj(object obj,object ob)
{
        message_vision(HIR"\n$N大叫到：你跑到天涯海角也逃不过本教的制裁！\n"NOR,obj);
        destruct(obj);
        destruct(ob);
}
void die()
{
        object ob = this_object();
        object me = ob->query("owner");
        object fighter;

        fighter=ob->query("fighter");
        if(fighter)
        {
        message_vision(CYN"\n$N说到：早知今日，何必当初！\n"NOR,ob);
        message_vision(CYN"\n$N说道：任务完成了，快回去向教主复命！\n"NOR,fighter);
        destruct(fighter);
        }
        me->delete("cttask/get");
        me->set("cttask/fail",1);

        ::die();
}

