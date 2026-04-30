// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("老板娘", ({ "boss" }) );
        set("gender", "女性" );
        set("age", 52);
        set("long",
                "老板娘善长补衣服，补出来的衣服又牢固而且不难看。\n");
        set("combat_exp", 50);
        set("str",200);
        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_bu","bu");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "老板娘笑道：这位" + RANK_D->query_respect(ob)
                                + "，你的衣衫看起来好象要补一下了。\n");
                        break;
                case 1:
                        say( "老板娘说道：这位" + RANK_D->query_respect(ob)
                                + "，你的衣衫都被人砍破了，来补一下吧。\n");
                        break;
        }
}

int  do_bu(string arg)
{
        object me, ob;
        object gold;
        int cost = 1;
        int i,j,base,current;
        string id,name ;        
        // 2026-04-30: unused variable commented out
        // string file,newfile,filestring;
        me = this_player();
        id = me->query("id");
        if( !arg ) return notify_fail("你要补什麽衣物？\n");
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("你身上没有金子。\n");
        if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
        if( !ob->query("armor_prop") )
        return notify_fail("你只能补穿在身上的东西。\n");
        if( ob->query("equipped") )
        return notify_fail("你不可补正穿着的衣物。\n");
        if( (ob->query("owner"))!=(me->query("id")) )
                return notify_fail("你只可补自己订的衣物。\n");
        if( (int)me->query("wlshw")<1)
        return notify_fail("你的武林声望不够补衣服的。\n");
        base= 10;
        current = (int) me->query("custom_cloth/"+ob->query("armor_type")+"/armor")/2;  
//        if (current>80) return notify_fail("这件衣服已经不能补了。\n");
        if (current<80)  {
        for(j=1;j<=100;j++)
        {
                base = base + j;
                if(base >= current) break;
        }
        for(i=1; i<= j;i++)
                        cost = cost * 2;
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d",cost)+ "两金子。\n");
        gold->add_amount(-cost);
        ob->set("armor_prop/armor",current*2 + 8);        
        me->set("custom_cloth/"+ob->query("armor_type")+"/armor",current*2+8);
        ob->move(me);
        message_vision(sprintf("$N拍了拍%s，说道：好了！\n",ob->query("name")),this_object());
        me->set("wlshw",(int)me->query("wlshw")-1);
        me->save();
        return 1;
        }else{

                if( (int)me->query("wlshw")<2)
                return notify_fail("你的武林声望不够给你的衣服换面料。\n");
                if (current>160) 
                return notify_fail("这已经是最好的面料了，你要再补就是补丁落补丁了。\n");

        for(j=1;j<=100;j++)
        {
                base = base + j;
                if(base >= current) break;
        }
        for(i=1; i<= j;i++)
                        cost = cost * 2 ;
        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d",cost)+ "两金子。\n");
        gold->add_amount(-cost);
        ob->set("armor_prop/armor",current*2 + 8);  
        me->set("custom_cloth/"+ob->query("armor_type")+"/armor",current*2+8);
        ob->move(me);
        message_vision(sprintf(HIC"$N从柜台后面拿出一匹"+HIY"金蚕丝"+HIC"来，在%s"+HIC"上面又添了块布料，说道：好了！\n"NOR,ob->query("name")),this_object());
        me->set("wlshw",(int)me->query("wlshw")-2);
        me->save();
        return 1;
        }
}

