// wokou.c
// by Tang


#include <ansi.h>
inherit "/std/char/doomnpc";

int remove_effect(object ob);
int consider();


string *first_name = ({ "龟田","武宫","小林","山本","田中","西条",
"上杉","丰臣","木下","桥本","竹下","酒井" });
string *name_words = ({ "太郎","次郎","三郎","四郎",
"秀季","英机","雷臧","康夫","原","健","刚造","三十七", });

int random_go();

void create()
{
        int i;

        string name, id;

        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "dongying renzhe", "renzhe" }) );

        set("title", HIR"东瀛"+HIW"忍者"NOR);
        set("gender", "男性" );
        set("shen_type", -1);
        set("age", 30+random(30));
        set("str", 100);
        set("cor", 100);
        set("cps", 100);
        set("int", 100);
        set("bln", 100);
        set("con", 100);
        set("wil", 100);
        set("vis", 100);
        set("long",
                "这是东瀛秘密派来盗取中原武学秘笈的忍者，前几批人手太逊，已在中土全军覆灭，\n想不到小小的日本国却还有这样的高手，不到寥寥数日，中原武林的精髓已被这些天资极高的倭人窃得！\n" );

        set("attitude", "aggressive");

        i=random(50)+50;

        set("combat_exp",i*i*i*10);

        set("eff_kee",5000+i*100);
        set("max_kee",5000+i*100);
        set("eff_gin",500+i*10);
        set("max_gin",500+i*10);
        set("eff_sen",500+i*10);
        set("max_sen",500+i*10);
        set("max_force",i*100);
        set("force",i*200);
        set("force_factor",i*3);
        set("food",1000);
        set("water",1000);

        set_skill("taiji-shengong", i*4);
        set_skill("xuanming-shenzhang", i*4);
        set_skill("move", i*4);
        set_skill("mysterrier", i*4);
        set_skill("stormdance", i*4);
        set_skill("spring-blade", i*4);
        set_skill("qiankun-danuoyi", i*4);
        set_skill("blade", i*4);
        set_skill("dodge", i*4);
        set_skill("parry", i*4);
        set_skill("strike",i*4);
        set_skill("force", i*4);
        set_skill("dugong",i*4);
        set_skill("dagou-bang",i*4);
        set_skill("throwing",i*4);
        set_skill("tiannv-sanhua",i*4);
        set_skill("perception",i*4);


        map_skill("force","taiji-shengong");
        map_skill("throwing","tianvn-sanhua");
        map_skill("strike","xuanming-shenzhang");
        map_skill("parry","qiankun-danuoyi");
        map_skill("dodge","stormdance");
        map_skill("move","mysterrier");
        map_skill("blade","spring-blade");
        prepare_skill("strike", "xuanming-shenzhang");
        set("skill_mark/spring-blade",1);

        set_temp("apply/attack",  i*2);
        set_temp("apply/defense", i);
        set_temp("apply/damage",  i*3);

        set("chat_chance",50);
        set("chat_msg", ({
               (: random_go :)
        }) );

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        set("bellicosity", 10000);
        set("jap_level",i-50);
        
        setup();
        
        carry_object("/d/wizard/npc/obj/shuiyue")->wield();
        carry_object("/d/suzhou/npc/obj/cloth")->wear();
        //if (random(3) > 1 )carry_object("/u/m/masterall/obj/hbook");

}

void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
        object me, room1;
        if( !ob || !objectp(ob) ) return;
        me = this_object();
        room1 = environment(me);


        if(ob->query("id")=="dongying renzhe") return 0;
                command("say 前几日听说江湖上出现传说中的玄天秘笈，没想到都是赝品！\n");
                command("say 真正的玄天秘笈已经落入我手，哈哈哈哈哈哈！！！！！！！\n");
                me->set_leader(ob);
                kill_ob(ob);
             if(!userp(ob) && !me->query("have_report") )
             {
                if ( me->query("jap_level") < 10 )
                {
                message("system",HIR "\n【纵横天下】"+ob->name()+HIR":中原出现一武功"+HIY"略有大成"+HIR"的东瀛忍者，请各路大侠迅速前往将其铲除，\n"+me->name()+HIR"你这个穷凶极恶的畜生，"+RANK_D->query_self_rude(ob)+"和你拼了！！\n"NOR,users() );
                me->set("have_report", 1);
                ob->kill_ob(this_object());
                }
                else if ( me->query("jap_level") >= 10 && me->query("jap_level") < 20 )
                {
                message("system",HIR "\n【纵横天下】"+ob->name()+HIR":中原出现一武功"+HIC"旷古绝伦"+HIR"的东瀛忍者，请各路大侠迅速前往将其铲除，\n"+me->name()+HIR"你这个穷凶极恶的畜生，"+RANK_D->query_self_rude(ob)+"和你拼了！！\n"NOR,users() );
                me->set("have_report", 1);
                ob->kill_ob(this_object());
                }
                else if ( me->query("jap_level") >= 20 && me->query("jap_level") < 30 )
                {
                message("system",HIR "\n【纵横天下】"+ob->name()+HIR":中原出现一武功"+HIG"无可匹敌"+HIR"的东瀛忍者，请各路大侠迅速前往将其铲除，\n"+me->name()+HIR"你这个穷凶极恶的畜生，"+RANK_D->query_self_rude(ob)+"和你拼了！！\n"NOR,users() );
                me->set("have_report", 1);
                ob->kill_ob(this_object());
                }
                else if ( me->query("jap_level") >= 30 && me->query("jap_level") < 40 )
                {
                message("system",HIR "\n【纵横天下】"+ob->name()+HIR":中原出现一武功"+HIM"超凡入圣"+HIR"的东瀛忍者，请各路大侠迅速前往将其铲除，\n"+me->name()+HIR"你这个穷凶极恶的畜生，"+RANK_D->query_self_rude(ob)+"和你拼了！！\n"NOR,users() );
                me->set("have_report", 1);
                ob->kill_ob(this_object());
                }
                else
                {
                message("system",HIR "\n【纵横天下】"+ob->name()+HIR":中原出现一武功"+HIW"深不可测"+HIR"的东瀛忍者，请各路大侠迅速前往将其铲除，\n"+me->name()+HIR"你这个穷凶极恶的畜生，"+RANK_D->query_self_rude(ob)+"和你拼了！！\n"NOR,users() );
                me->set("have_report", 1);
                ob->kill_ob(this_object());
                }
             }
}


int killed_enemy(object ob)
{
     object riben= this_object();
     message("system",HIW "\n【纵横天下】抗日英豪(KANG RI)："+riben->name()+"用拗口的汉语嗤笑道，“寥寥中土，也不过如此！啊哈哈哈哈哈哈～～～～～～！！！！！”\n"NOR,users() );
     add("force", 100);
}                 


void die()
{
        mapping victims;
        string *vic;
        int i,exp,pot,wlshw,gift;
        object riben;
        object ob;


        ob = this_object()->query_temp("last_damage_from");
        gift = this_object()->query("jap_level");
        riben = this_object();
                
                if (objectp(ob))
                {
                        exp = random(10000) + gift*300;
                        pot = random(5000) + gift*150;
                        wlshw = random(5) + gift/10;

                        ob->add("combat_exp",exp);
                        ob->add("potential",pot);
                        ob->add("wlshw", wlshw);
                        ob->add("eff_kee", -1*ob->query("max_kee")/2);
                        message_vision(HIR"$N狰狞二目，如野兽般嘶嚎着，“玄天秘笈的绝本已妥善交给德川大将军了，\n你们这些满口仁义道德的中国人，我们早晚有一天还会回来的！！等着下地狱吧！”\n话毕，竟施出了中原魔教绝迹江湖多年的——“血爆！”$n一个躲闪不及，已被卷入了漫天血雨！！\n"NOR,this_object(),ob);
                        message("system",HIC "\n【纵横天下】抗日英豪(KANG RI)："+ob->name()+"浴血奋战，终于将东瀛忍者诛灭，\n"+HIG"得到了"+chinese_number(exp)+"点经验、"+chinese_number(pot)+"点潜能、"+chinese_number(wlshw)+"点武林声望的奖励！！\n"NOR,users() );
                        
                }
        ::die();

}

int random_go()
{
        mapping exits;
        string *dirs;
        if(is_fighting()) return 0;
        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
        command("go " + dirs[random(sizeof(dirs))]);
}

int consider()
{
        if( query("env/invisibility") || !is_fighting() ) 
        {
 //               command("exert suck");
                return 0;
        }
        message_vision(WHT"$N手似乎动了动，全身立即笼罩在一阵烟雾中，瞬间已不见了$N的踪影。\n"NOR,this_object());
        set("env/invisibility",1);
        call_out("remove_effect",60,this_object());                     
        return 1;
}                              

int remove_effect(object me)
{
        remove_call_out("remove_effect");
        message_vision(BLU"$N"+BLU"突然从地下蹿了出来，那一闪间的速度的确比耗子上房还要快。\n"NOR,me);
        me->delete("env/invisibility");
        return 1;
}

