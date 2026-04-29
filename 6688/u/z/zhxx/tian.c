#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "高空");
        set("long", @LONG
你飞到了高空，整个大陆竟然一览无遗。你准备往哪儿去呢？
星宿派 xingxiu   天邪派 tianxie   茅山派 maoshan  日月神教 heimuya
明教   mingjiao  武当派 wudang   全真派 quanzhen   步玄派（乔阴） buxuan
华山气宗 hsqi    华山剑宗 hsjian  桃花岛 taohua  晚月庄 latemoon
唐门    tangmen   雪亭 snow      京城 jingcheng   绮云镇 cloud
北京 beijing     岳阳 yueyang     铁血 tieflag    青城 qingcheng
娥眉 emei        福州 fuzhou      苏州 suzhou    杭州 hangzhou
西夏 xixia       灵蛇岛 lshdao    长春岛 ccdao   军营 canyon
西藏 xizang
LONG);
         set("no_kill",1);
         set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1);
         set("exits",
         ([
                "xingxiu" : "/d/xingxiu/xxh1",
                "canyon" : "/d/canyon/camp1",
                "tianxie" : "/d/waterfog/entrance",
                "cloud" : "/d/cloud/nwroad3",
                "buxuan" : "/class/scholar/entrance",
                "hsjian" : "/d/huashan/bieyuan",
                "hsqi" : "/d/huashan/gate",
                "maoshan" : "/d/taoguan/da_dian",
                "mingjiao" : "/d/mingjiao/shanmen",
                "wudang" : "/d/wudang/sanqingdian",
                "heimuya" : "/d/heimuya/cdd",
                "hangzhou" : "/d/hangzhou/h_cross2",
                "quanzhou" : "/d/quanzhou/houyuan",
                "jingcheng" : "/d/jingcheng/tamgch",
                "taohua" : "/d/taohua/houhuayuan",
                "snow" : "/d/snow/inn",
                "beijing":"/d/beijing/square",
                "yueyang" : "/d/yueyang/guangchang",
                "tangmen" : "/d/tangmen/gate",
                "quanzhen" : "/d/quanzhen/sanqingdian",
                "tieflag" : "/d/tieflag/goldroom",
                "qingcheng":"/d/qingcheng/square",
                "emei":"/d/emei/gate",
                "fuzhou":"/d/qingcheng/beimen",
                "latemoon":"/d/latemoon/latemoon1",
                "suzhou":"/d/suzhou/shizx",
                "xixia":"/d/xixia/southsquare",
                "lshdao":"/d/mingjiao/lshd1",
                "ccdao":"/d/tieflag/island",
                "xizang" : "/d/xizang/inn",
        ]));
        setup();
        replace_program(ROOM);
}

