//by zephyr
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
void create()
{
        set_name("柳若松", ({ "liu ruosong","liu"}) );
        set("long",YEL@LONG
他本是名满天下的“岁寒三友”中的“青松剑客”。
也是武当山玄真观，天一真人门下唯一的俗家弟子。
但后来为了一把叫做“小楼一夜听风雨的”的神刀，他
毒杀了丁鹏的仆从铜驼，虏走了丁鹏的儿子。有此刀
在手，加上魔教的神刀斩，天下几乎无人是他的对手。
只有一个人，一个会让他做恶梦的人，他没有把握战胜
那个人就是丁鹏。
LONG NOR
         );

        set("title",YEL"神刀山庄"WHT"庄主"NOR);
        set("age", 50);
        //set advanced skills
        create_family("万松山庄", 7, "庄主");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: exert_function, "recover" :),
        }) );

        set_skill("force", 400);
        set_skill("strike", 400);
        set_skill("sword", 400);
        set_skill("blade", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("perception", 400);
                
        set_skill("taiji-shengong", 280);
        set_skill("celestrike", 400);
        set_skill("spring-blade", 400);
        set_skill("pyrobat-steps", 400);
        map_skill("force", "taiji-shengong");
        map_skill("strike","celestrike");
        prepare_skill("strike", "celestrike");
        map_skill("blade", "spring-blade");
        map_skill("dodge", "pyrobat-steps");
 
    set("shen_type",-1);
    set("skill_mark/spring-blade",1);

        
        set("attitude", "peaceful");
        set("combat_exp", 20000000);
        set("shen_type",-1);

        set("str", 100);
        set("int", 30);
        set("cor", 100);
        set("cps", 100);                       
        set("per", 30);
        set("con", 30);
        set("no_get",1);

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 20000);
        set("max_force", 10000);
        set("force_factor", 300);

        set("mana", 5000);
        set("max_mana", 5000);

        set("max_kee",100000);
        set("max_gin",20000);
        set("max_sen",20000);

        set_temp("apply/defense",100);
        set_temp("apply/armor_vs_force",1000);
        set_temp("apply/armor",1000);
        
        set("bellicosity",1000);
        set("dingpeng_enemy",1);

    setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object(__DIR__"moonblade")->wield();
        set("bellicosity",1000);
}                          

                             
int killed_enemy(object ob)
{
        command("laugh");
        command("say "+"自此我神刀一出，天下谁与争风！！\n");
        call_out("leave",200);
}                 

void die()
{
        object me, blade,killer;
        me=this_object();
        blade = present("moon blade", me);

        if( objectp(killer = query_temp("last_damage_from")) )
    if( environment() && killer->query("id")=="ding peng") 
        {
                killer->set_temp("dingpeng/kill_liuruosong",1);
                message("vision", CYN"\n\n丁鹏忽然低吼一声，举起手中木刀直砍下来，正是魔教“神刀斩”\n", environment());
                message("vision", CYN"\n柳若松冷笑一声，也以同样的招式回击\n", environment());
                message("vision", CYN"\n柳若松出手较慢，但他手中却是百坚不摧的圆月弯刀，他有绝对的信心胜过丁鹏\n"NOR, environment());
                message("vision", CYN"\n两刀相触时，柳若松忽然想起了那柄木刀的珍奇，不免顿了一顿\n"NOR, environment());
                message("vision", CYN"\n这本来就是丁鹏所预期的，他所要争取的是速度。\n"NOR, environment());
                message("vision", CYN"\n刀与刀一触即分，木刀自然无法胜过神刀的，被劈成了两片。\n"NOR, environment());
                message("vision", CYN"\n但是丁鹏的攻势却没断，两片木刀直下，柳若松的人分成了三片。\n"NOR, environment());
        }
        ::die();
}
int leave()
{
   command("bye");
   destruct(this_object());
}
