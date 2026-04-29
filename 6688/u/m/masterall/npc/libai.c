// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
int give_task();

int carrying;

void create()
{
        set_name("李白", ({ "li bai" , "li" , "bai" }));
        set("nickname", CYN"诗仙"NOR); 
        set("long",
        "他是大诗人李白，清高飘逸，卓尔不群，乃是人中龙凤。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("max_kee", 800);
        set("max_gin", 800);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 5);
        set("combat_exp", 50000);
        set("score", 100000);
        set_skill("sword",50);
        set_skill("force", 40);
        set_skill("dodge", 50);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
        set_temp("give_task",1);
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "李白大笑道：“五花马，千金裘，呼尔将来换美酒，与尔同销万古愁。\n",     
        }) );
        set("inquiry", ([
                           "精忠报国":(:give_task:),
                        ]));

        carry_object("/d/jingcheng/npc/obj/cloth")->wear();
        carry_object("/d/jingcheng/npc/obj/gangjian")->wield();
}
void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}
void greeting(object me)
{
        command("say 这位"+(string)RANK_D->query_respect(me)+"可否与"+
        RANK_D->query_self(this_object())+"共谋一醉？\n");
}


int accept_object(object who, object ob)
{
                if(who->query("national_gift"))return 0;
                if (ob->query("id")!="shou ji")return 0;
                if(ob->query("owner") == who)
                {
                        message_vision("$n给了$N一颗倭寇的" + ob->name() + NOR"。\n", this_object(),who);
                        command("nod");
                        message_vision(CYN"$N对$n说道：做得不错，希望$n继续为国争光，打得那帮小日子再也不敢犯我国土！\n"NOR, this_object(),who);
                        who->set("national_gift",1);
//                        who->add("wlshw",10);
                        who->add("combat_exp",200000);
                        who->add("potential",100000);
                        set_temp("give_task",1);
                        destruct(present("shou ji",who));
                        message("channel:chat", 
                        HIC + "【闲聊】" + name() + HIC"(" + capitalize(query("id")) +
                         ")：" + who->name() + "歼灭倭寇一只，特奖励" + 
                        who->name() + "经验20万点，潜能10万点，以资鼓励。\n"+NOR,users());
                        command("pat " + who->query("id"));
                        command("addoil " + who->query("id"));
                        return 1;
                }else{
                        message_vision("$n给了$N一颗倭寇的" + ob->name() + NOR"。\n", this_object(),who);
                        command("heng");
                        message_vision(RED"$N对$n冷冷一笑：这颗首级是从哪里搞来的？国难当头，你却投机倒把当其汉奸卖国贼，其罪难恕！！\n"NOR, this_object(),who);
                        who->set("national_gift",1);
                        who->add("wlshw",-20);
                        who->add("combat_exp",-400000);
                        who->add("potential",-200000);
                        destruct(present("shou ji",who));
                        message("channel:chat", 
                        HIC + "【闲聊】" + name() + HIC"(" + capitalize(query("id")) +
                         ")：" + who->name() + "用假冒的倭寇首级励来骗取奖励，受到了严厉的惩罚，希望大家引以为鉴。\n"+NOR,users());
                        who->move("/d/wizard/jianyu");
                        return 1;
                }

}

int give_task()
{
        int i;
    object *inv;
        object me=this_player();
        object ob=this_object();

        inv = all_inventory(me);
        for( i=0;i<sizeof(inv);i++) 
        {
                if( inv[i]->is_character() )
                {
                        write(HIR"你不能背着"+inv[i]->query("name")+"去杀鬼子，想用bug？去死吧!\n"NOR);   
                        me->set_temp("last_damage_from", ob);
                        me->die(); 
                        return 1;
                }
        }
        
        if( !ob->query_temp("give_task") )
        {
               command("sigh");
               command("say 现在已经有人去杀鬼子了，等下次吧。\n");        
                        return 1; 
        }

        if (me->query("national_gift"))
        {
               command("say 你已经领过一次杀倭寇的任务了，还是等今后有机会再说吧！！");
                        return 1;
        }

if ( sizeof(inv) ){
        map_array(inv, "drop_npc");
                if ( carrying )
                return notify_fail("不能背着其他生物去杀倭寇！\n");}
        
        if (me->query("combat_exp")<50000)
        {
               command("say 你还太弱了，小心命丧倭寇之手！");
                        return 1;
        }
        ob->delete_temp("give_task");
        message_vision(HIY"\n现在东南沿海倭寇猖獗，它们烧杀抢掠，奸淫妇女，无所不为。\n"NOR,ob,me);        
        message_vision(HIY"\n国难当头，每个热血衷肠的中华儿女都要为国出力，$n能有如此爱国之心，确实难得。\n"NOR,ob,me);    
        message_vision(HIY"\n如此这般，$n尽管去好了，保重啊壮士！！\n"NOR,ob,me);  
        message_vision(HIG"\n\n$N曼声吟道，“风萧萧兮易水寒，壮士一去兮不复还！！！”\n"NOR,ob,me);      

        tell_object(me,HIR"你听罢，顷刻间热血沸腾，身为炎黄子孙，华夏儿女，在国难当头之际怎可坐视不理！\n想到此处，你居然想起一句戏文来，“看前面，黑洞洞，定是那贼巢穴，待俺赶上前去，杀它个干干净净！！”\n"NOR);

        me->move("/u/m/masterall/cun");
        me->set("kill_wokou",1);

        return 1;
}

