/* compare.c by dongsw
   
   写这个主要是为了比较新生成的roomlog、npclog、npc_roomlog
   和现在正在使用的有什么不同，以便更改和管理
   耗费资源，慎用！
*/

int main(object me, string arg)
{ 
        int k, i;
        string arg1, arg2, arg3, arg4;
        
        if(!arg || arg == "")
                return notify_fail("你要比较什么文件？\n");
        
        if(sscanf(arg, "%s %s", arg1, arg2) == 2 )
        {
                if(file_size(arg1) < 0)
                        return notify_fail("文件" + arg1 + "不存在！\n");
                
                if(file_size(arg2) < 0)
                        return notify_fail("文件" + arg2 + "不存在！\n");
                                                
                write("文件1：" + arg1 + "\n");
                write("文件2：" + arg2 + "\n\n");
                arg4 = read_file(arg1);
                for(k=0;k<(sizeof(explode(read_file(arg2),"\n")));k++) 
                {
                        arg3 = read_file(arg2,k+1,1);
                        if( strsrch(arg4,arg3) == -1)
                        {
                                printf("文件（%s）中的第 %d 行文件（%s）没有！\n",arg2,k+1,arg1);
                                i++;
                        }
                }
                write("\n");
                arg4 = read_file(arg2);
                for(k=0;k<(sizeof(explode(read_file(arg1),"\n")));k++) 
                {
                        arg3 = read_file(arg1,k+1,1);
                        if( strsrch(arg4,arg3) == -1)
                        {
                                printf("文件（%s）中的第 %d 行文件（%s）没有！\n",arg1,k+1,arg2);
                                i++;
                        }
                }
                write("\n");
                write("文件（" + arg1 +"）与文件（" + arg2 + "）比较完毕！\n");
                write("\n");
                printf("总共发现 %d 个不同的地方。\n",i);
        }
        else write("请用 compare [文件1路径] [文件2路径] 的格式来执行！\n");
        return 1;
} 

