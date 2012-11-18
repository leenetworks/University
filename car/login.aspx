<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="login.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>
    <style type="text/css">
        #form1
        {
            height: 348px;
        }
    </style>

</head>
<body>
 
    <form id="form1" runat="server">
      <br />
      <br />
      <br />
      <br />
      <br />
      <asp:Table runat="server" HorizontalAlign="center" BackColor="#CCFFCC" 
          BorderColor="Blue">
        <asp:tableRow>
         <asp:TableCell>
           <asp:Label ID="Label1" runat="server" Text="用户名："></asp:Label>
         </asp:TableCell>
         <asp:TableCell>
          <asp:TextBox ID="TextBox1" runat="server" EnableViewState="False"></asp:TextBox>
         </asp:TableCell>
        </asp:tableRow>
       <asp:tableRow>
         <asp:TableCell>
           <asp:Label ID="Label2" runat="server" Text="密码："></asp:Label>
         </asp:TableCell>
         <asp:TableCell>
          <asp:TextBox ID="TextBox2" TextMode="Password" runat="server"></asp:TextBox>
         </asp:TableCell>
        </asp:tableRow>
       <asp:TableRow>
          <asp:TableCell ColumnSpan="2" HorizontalAlign="center">
          <asp:Button ID="Button1" runat="server" Text="提交"  OnClick="Button1_Click"/>
          
          </asp:TableCell>
       </asp:TableRow >
        
      </asp:Table>
    <br />
 <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
          ConnectionString="<%$ ConnectionStrings:dbCarConnectionString %>" 
          SelectCommand="SELECT * FROM [tb_user]"></asp:SqlDataSource>;
 </form>
  
</body>
</html>
