//story_msg.h
//by tlang for wisdomer 

string *secret_msg1=({
"听说过诸葛先生吗？要见他需要一张老虎皮，拿着这东西进入宁王府，\n",
"在大观园西部的石林中找到白雕，给它虎皮，然后它会给你一只羽毛。\n",
"接着你到园子东部的荷塘，下到水中，用羽毛撩撩守门的鳗鱼的鼻孔，\n",
"它就会让你进去的。\n",
});

string *secret_msg2=({
"知道黛玉吗？八月十五晚上你不妨到潇湘馆外面去看看，看能发现什么？\n",
"知道段家的少爷段玉吗？当你经验较高时，和他说说话，说不准会有意外的收获。 \n",
"知道怎么恢复做手术掉的经验吗？如果不知道，不防到西湖上听听舞姬说些什么。\n",
"听说过宁王府每月十五的诗会吗？还有每年元宵前夕的灯谜大会？你不防去看看。\n",
"雪亭镇有个酒鬼,知道吧?在旁边听听他要什么.也许有什么意外发现.\n",
"学功夫不要只象masters学，要找些书来读，也可以付出一些代价，找一些闲人异士学:\n",
"如漪云镇的李师师，华山的风清扬，岳阳的朱僖，雪亭镇的魏无极。。。。。\n",
"只要你善于发现，会有许多意外收获的。\n",
"知道黑风堡吧？和堡下的某个人说说话，也许有特别的事情发生。\n",
});

string *secret_msg3=({
"不知道你有没有听说过混世神剑的故事？\n",
"不管你听没听说过，我告诉你怎样才能得到它：\n",
"混世神剑是要寒于三宝凑齐后由小霖施法炼成，\n",
"旋芒宝剑在雪山上，要取得十分困难；邪剑穿灵在苏州，多找人说说话，应该没问题；\n",
"寒于宝衣在杭州西湖底，听说要找西湖上一位姑娘帮忙才行。呵呵\n",
"至于关于混世神剑的故事，你可以到苏州城外找王安石打听。\n",
});

void tell_story_msg1(object who,int stage)
{
	tell_object(who, secret_msg1[stage]); 
	if( ++stage < sizeof(secret_msg1) )
	{
		call_out("tell_story_msg1",1,who,stage);
			return;
	}	
}

void tell_story_msg2(object who,int stage)
{
	tell_object(who, secret_msg2[stage]); 
	if( ++stage < sizeof(secret_msg2) )
	{
		call_out("tell_story_msg2",1,who,stage);
			return;
	}	
}

void tell_story_msg3(object who,int stage)
{
	tell_object(who, secret_msg3[stage]); 
	if( ++stage < sizeof(secret_msg3) )
	{
		call_out("tell_story_msg3",1,who,stage);
			return;
	}	
}

string story_status_msg()
{
	object who=this_player();

        switch (random(3)) 
	{
	case 0:
		call_out("tell_story_msg1",2,who,0);
		break;
	case 1:        
                call_out("tell_story_msg2",2,who,0);
     		break;
	case 2:
	        call_out("tell_story_msg3",2,who,0);
        	break;
	}                                                        
}
