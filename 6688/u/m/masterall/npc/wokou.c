#include <ansi.h>

inherit "/std/char/doomnpc";

string *first_name = ({ "龟田","武宫","小林","山本","田中","西条",
"上杉","丰臣","木下","桥本","竹下","酒井" });
string *name_words = ({ "太郎","次郎","三郎","四郎",
"秀季","英机","雷臧","康夫","原","健","刚造","三十七", });

string ask_me(object who);

void create()
{
        int i;

        string name, id;

        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];

        set_name(name, ({ "wo kou" }) );
        set("long",
                "这是个来日本的小鬼子，留着一撇小黑胡，正色咪咪的盯着你。\n" );
        set("title",HIR"日本"+HIW"鬼子"NOR);
        set("nickname",HIB"坏事做绝，天良丧尽"NOR);
        set("attitude", "aggressive");



        set_temp("apply/damage",100);
        set_temp("apply/attack",50);
        set_temp("apply/defense",10);



        setup();

        carry_object("/d/suzhou/npc/obj/wushidao")->wield();
        carry_rnd_equip(3,3);   
}                          

int init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        set("shen",-1*this_player()->query("shen")/10);
        set("max_gin", this_player()->query("gin")*10);
        set("max_kee", this_player()->query("max_kee")*10);      
        set("kee", this_player()->query("max_kee")*10); 
        set("gin", this_player()->query("max_gin")*10); 
        set("sen", this_player()->query("max_sen")*10); 
        set("eff_kee", this_player()->query("max_kee")*10); 
        set("eff_gin", this_player()->query("max_gin")*10); 
        set("eff_sen", this_player()->query("max_sen")*10);               
        set("max_sen", this_player()->query("max_sen")*10);
        set("max_force",this_player()->query("max_force")); 
        set("max_mana",this_player()->query("max_mana"));
        set("mana",this_player()->query("mana"));
        set("max_atman",this_player()->query("max_atman"));
        set("atman",this_player()->query("atman"));
        set("force",this_player()->query("max_force")*2);
        set("force_factor",this_player()->query("force_factor")/2);     
        set("combat_exp",this_player()->query("combat_exp"));
        set("cor",this_player()->query("cor"));
        set("cps",this_player()->query("cps"));   
        set("spi",this_player()->query("spi"));
        set("str",this_player()->query("str"));
        set("bln",this_player()->query("bln"));


        set_skill("blade", this_player()->query_skill("force")*2);
        set_skill("dodge", this_player()->query_skill("dodge")*2);
        set_skill("parry", this_player()->query_skill("parry")*2);
        set_skill("force",this_player()->query_skill("force"));
        set_skill("huashan-neigong", this_player()->query_skill("force"));
        map_skill("force", "huashan-neigong");


        return 1;
}
   


void greeting(object ob)
{
        
        if( !ob || environment(ob) != environment() ) return;

                if(ob->query("gender")!="女性")
                                return;
                if(ob->query("per")<=20 )
                        {
                 command("hmm "+ob->query("id"));
                 command("say 花姑娘大大的，来来来，让太君亲上一口！！");
                                return;
                        }
                 command("kiss "+ob->query("id"));
                 command("say 花姑娘大大的，来来来，让太君亲上一口！！");
        return;

}

                          
int killed_enemy(object ob)
{
        command("haha");
        destruct(this_object());
        message("system",HIR "\n【纵横天下】抗日英豪(KANG RI)："+ob->name()+"在与倭寇的战斗中壮烈牺牲，他虽死犹生，值得我们景仰和缅怀。\n【纵横天下】抗日英豪(KANG RI)：希望我辈中人能承其遗志，奋勇杀敌，将倭寇彻底铲除！！\n" NOR,users() );
}                 
                     
void die()
{
        mapping victims;
        string *vic;
        int i;
        object player;
        object ob, obj;

        ob = this_object()->query_temp("last_damage_from");
        if( ob && ob->query("kill_wokou") && userp(ob) )
        {       
                obj = new("/u/m/masterall/obj/head");
                obj->move(ob);
                obj->set("owner",ob);
                message_vision(HIR"\n$N还喊道，“八格牙鲁，你的厉害的大大，我的打你不过”，说罢扭头就跑！\n"+HIC"\n$n那还能容这厮逃窜，一个箭步冲上前去随手给予$N致命一击，$N腿脚踢腾了几下，一命归西了。\n"+HIG"$n还觉得有些不解气，寒芒一闪，割下了$N的首级，一脚提得老高，用破布裹起来，装入怀中。\n\n"NOR,this_object(),ob);
                message("system",HIC "\n【纵横天下】抗日英豪(KANG RI)："+ob->name()+"英勇奋战，终于将倭寇铲除一只，请到京城领取奖励！！\n" NOR,users() );
        }
        ::die();

}


