inherit ROOM;
void create()
{        
        set("short", "高空");
        set("long", @LONG
你飞到了高空,你现在要往哪里飞呢???请选择一下吧!!
星宿 xingxiu 军营 canyon 天邪 waterfog 绮云镇 cloud 茅山 taoguan 黑木崖 heimuya 杭州 hangzhou
泉洲 quanzhou 京城 jingcheng 雪山 xueshan 桃花岛 taohua 泰山 taishan 乔阴 choyin 雪亭 snow
北京 beijing 岳阳 yueyang 唐门 tangmen 青石村 green 全真 quanzhen 铁血 tieflag 青城 qingcheng
娥眉 emei 成都 chengdu 福州 fuzhou 晚月 latemoon 苏州 suzhou 西夏 xixia
灵蛇岛 lingshedao 长春岛 changchun
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
                "waterfog" : "/d/waterfog/entrance",
                "cloud" : "/d/cloud/nwroad3",
                "taoguan" : "/d/taoguan/da_dian",
                "heimuya" : "/d/heimuya/cdd",
                "hangzhou" : "/d/hangzhou/h_cross2",
                "quanzhou" : "/d/quanzhou/houyuan",
                "jingcheng" : "/d/jingcheng/tamgch",
                "xueshan" : "/d/xueshan/house",
                "taohua" : "/d/taohua/houhuayuan",
                "taishan" : "/d/taishan/fengchan",
                "choyin" : "/d/choyin/hotel1",
                "snow" : "/d/snow/inn",
                "beijing":"/d/beijing/square",
                "yueyang" : "/d/yueyang/guangchang",
                "tangmen" : "/d/tangmen/gate",
                "green" : "/d/green/path2",
                "quanzhen" : "/d/quanzhen/sanqingdian",
                "tieflag" : "/d/tieflag/goldroom",
                "qingcheng":"/d/qingcheng/square",
                "emei":"/d/emei/gate",
                "chengdu":"/d/chengdu/guangchang",
                "fuzhou":"/d/qingcheng/beimen",
                "latemoon":"/d/latemoon/latemoon1",
                "suzhou":"/d/suzhou/shizx",
                "xixia":"/d/xixia/southsquare",
                "lingshedao":"/d/mingjiao/lshd1",
                "changchun":"/d/tieflag/island",
        ]));
        setup();
        replace_program(ROOM);
}

